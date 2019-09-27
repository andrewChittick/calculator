//main.cpp
//driver for a calculator
//Andrew Chittick
//12/1/18

#include <iostream>
#include <string>
#include "Calculator.h"
#include "Eval_Expr_Tree.h"

int main(int argc, char * argv []){
	Calculator * etb = new Calculator();

	bool keepGoing = true;
	std::string infix = "";

	while (keepGoing){
		std::cout<<"infix expression: ";
		getline(std::cin, infix);//getexpression
		if (infix == "QUIT"){
			keepGoing = false;
		}
		else if (etb->evaluate(infix)){//valid expr
			//print answer
			Expr_Node * expr_tree = etb->get_expression();//get the expr tree
			Eval_Expr_Tree eval;//initialize evaluator visitor
			expr_tree->accept(eval);//evaluate the expr_tree
			if (eval.result_valid()){//check that the answer is valid
				int result = eval.result();//get the result
				std::cout<<"visitor answer: "<<result<<std::endl;
			}
		}
		else{//invalid expr
			std::cout<<"invalid expression"<<std::endl;
		}
	}
	return 0;
}
