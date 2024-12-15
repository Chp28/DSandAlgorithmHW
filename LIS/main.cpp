#include <iostream>
#include <vector>
using namespace std;

class information{
public:
	int length;
	vector<double> child_arr;
	
	information(int length) : length(length) {}
	
	void print(){
		cout << length << endl;
		for(int i=0; i<child_arr.size(); i++){
			cout << child_arr[i] << " ";
		}
		cout << endl;
	}
};

information LIS(vector<double> arr){
	int size = arr.size();
	vector<int> max_length(size);
	vector<int> last_location(size);
	for(int i=0; i<size; i++){
		int max = 1;
		int pos = -1;
		for(int j=0; j<i; j++){
			if(arr[j]<arr[i] && max<(max_length[j]+1)){
				max = max_length[j]+1;
				pos = j;
			}
		}
		max_length[i] = max;
		last_location[i] = pos;
	}
	int max_pos = 0;
	int MaxLength = 1;
	for(int i=1; i<size; i++){
		if(max_length[i]>MaxLength){
			MaxLength = max_length[i];
			max_pos = i;
		}
	}
	information info(MaxLength);
	vector<double> temp(MaxLength);
	for(int i=MaxLength-1; i>=0; i--){
		temp[i] = arr[max_pos];
		max_pos = last_location[max_pos];
	}
	info.child_arr = temp;
	return info;
}

int main(){
	vector<double> arr = {2,43,23,65,32,6,33,74,13,5,75,21};
	information info = LIS(arr);
	info.print();
	return 0;
}

