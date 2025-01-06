#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

class Evaluator{
public:
    Evaluator(const string& expression) : expression{expression} {}
    void solve() {
    	try{
    		cout << _solve(expression) << endl;
    	} catch (const runtime_error& e) {
    		cerr << "an exception was caught: " << e.what() << endl;
    	}
    }
private:
    string expression;
    
    int Catch(int& index,const string& s){
	int cnt = 0;
	while(isNumber(s[index+cnt]) || s[index+cnt]=='.'){
		cnt += 1;
	}
	return cnt;
    }
    
    double string_to_double(const string& t){
    	double sum = 0;
    	int pos = 0;
    	for(pos; pos<t.size(); pos++){
    		if(t[pos]=='.')
    			break;
    	}
    	for(int i=0; i<t.size(); i++){
    		if(isNumber(t[i])){
    			if(i<pos){
    				sum += (t[i]-'0')*pow(10,pos-i-1);
    			}else{
    				sum += (t[i]-'0')*pow(10,pos-i);
    			}
    		}
    	}
    	return sum;
    }
    
    bool isNumber(char c){
    	return isdigit(c);
    }
    
    bool isOperator(char c) {
    	return c == '+' || c == '-' || c == '*' || c == '/';
    }
    
    double applyOperation(double a, double b, char op) {
	switch (op) {
	   	case '+': return a + b;
	        case '-': return a - b;
	        case '*': return a * b;
	        case '/': 
	            if (b == 0) {
	                throw runtime_error("the divisor can not be zero");
	            }
	            return a / b;
	        default:
	        	cout << op << endl; 
	        	throw runtime_error("unknown operation");
    	}
    }
    
    double compute(vector<double> Number, vector<char> Operator){
    	double Sum = Number[0];
    	for(int i=1 ; i<Number.size() ; i++){
    		if(Operator[i-1]=='*' || Operator[i-1]=='/'){
    			Sum = applyOperation(Sum,Number[i],Operator[i-1]);
    		}else{
    			if(i<Operator.size() && Operator[i]!='*' && Operator[i]!='/'){
    				Sum = applyOperation(Sum,Number[i],Operator[i-1]);
    			}else{
    				vector<double> temp_Number(Number.begin()+i,Number.end());
    				vector<char> temp_Operator(Operator.begin()+i,Operator.end());
    				double temp = compute(temp_Number,temp_Operator);
    				Sum = applyOperation(Sum,temp,Operator[i-1]);
    				break;
    			}
    		}
    	}
    	return Sum;
    }
    
    double _solve(const string s){
    	vector<double> Number;
    	vector<char> Operator;
    	int flag = 0;
    	int index = 0;
    	while(index<s.size()){
    		if(flag==0 && isNumber(s[index])){
    			int size = Catch(index,s);
    			string t = s.substr(index,size);
    			Number.emplace_back(string_to_double(t));
    			index = index+size;
    			flag = 1;
    			continue;
    		}
    		if(flag==1 && isOperator(s[index])){
    			Operator.emplace_back(s[index]);
    			index++;
    			flag = 0;
    			continue;
    		}
    		if(flag==0 && s[index]=='('){
    			int tail = index+1;
    			int sign = -1;
    			int cnt = 1;
    			for(tail; tail<s.size(); tail++){
    				if(s[tail]=='('){
    					cnt++;
    					continue;
    				}
    				if(s[tail]==')' && cnt==1){
    					sign = 0;
    					break;
    				}else if(s[tail]==')'){
    					cnt--;
    					continue;
    				}
    			}
    			if(sign==-1){
    				throw runtime_error("the number of parentheses does not match");
    			}else{
    				string t = s.substr(index+1,tail-index-1);
    				Number.emplace_back(_solve(t));
    				index = tail+1;
    				flag = 1;
    				continue;
    			}
    		}else{
    			throw runtime_error("the number does not match the operation");
    		}
    	}
    	
    	if(Number.size() != Operator.size()+1){
    		throw runtime_error("numbers do not match operations");
    	}
    	
    	double Sum = compute(Number,Operator);
    	return Sum;
    }
};
