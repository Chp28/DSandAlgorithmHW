#include <iostream>
#include "expression_evaluator.h"

int main() {
    string expression;
    while(1){
    	std::cout << "input: " << std::endl;
    	getline(cin, expression);
    	if(expression=="-1") //enter -1 to exit the main function
		break;
    	Evaluator solver = Evaluator(expression);
    	solver.solve();
    }
    return 0;
}
