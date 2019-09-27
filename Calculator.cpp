//Calculator.cpp

#include "Calculator.h"

Calculator::Calculator(void)
	:builder_(),
	postfix_()
{}

bool Calculator::evaluate (const std::string & infix){
	return (this->parse_expr(infix));
}

Expr_Node * Calculator::get_expression (void){
	return (this->builder_.get_expression());
}

int Calculator::get_answer(void){
	Expr_Node * expr = this->builder_.get_expression();
	return(expr->eval());
}

bool Calculator::parse_expr (const std::string & infix){

	builder_.start_expression();//start a new expression
	std::string token = "";

  // COMMENT: Do not go from infix to postfix then to tree. Instead,
  // go directly from infix to tree. The extra step is not necessary.

	if (infix2postfix(infix)){
		while (!postfix_.is_empty()){
			token = postfix_.dequeue();
			if (this->isNumber(token)) this->builder_.build_num_operator(stoi(token));
			else if (token == "+") this->builder_.build_add_operator();
			else if (token == "-") this->builder_.build_subtract_operator();
			else if (token == "*") this->builder_.build_multiply_operator();
			else if (token == "/") this->builder_.build_divide_operator();
			else if (token == "%") this->builder_.build_modulus_operator();
		}
	}
	else return false;
	return true;
}

bool Calculator::infix2postfix(const std::string & infix){

	std::istringstream input(infix);//create input stream parser
	std::string token;//current token in string/stream

	Stack <std::string> opstack;

	while (!input.eof()){
		input >> token;

		if (this->isNumber(token)){
			postfix_.enqueue(token);
		}
		else if (this->isOperator(token)){
			bool keepGoing = true;
			while (keepGoing == true){
				if (opstack.is_empty()){
					opstack.push(token);
					keepGoing = false;
				}
				else{
					if (getPrec(opstack.top()) >= getPrec(token)){
							postfix_.enqueue(opstack.top());
							opstack.pop();
					}
					else{
						opstack.push(token);
						keepGoing = false;
					}
				}
			}//end while
		}
		else if (token == "("){
			opstack.push(token);
		}
		else if (token == ")"){
			bool keepGoing = true;
			while (keepGoing){
				if (opstack.is_empty()){
					return false;
				}
				else{
					std::string op = opstack.top();
					opstack.pop();
					if (op == "("){//done
						keepGoing = false;
					}
					else{
						postfix_.enqueue(op);
					}
				}
			}//end of while
		}
		else return false;
	}
	while (!opstack.is_empty()){
		postfix_.enqueue(opstack.top());
		opstack.pop();
	}
	return true;
}

bool Calculator::isOperator(const std::string & token){
	if (token == "+") return true;
	else if (token == "-") return true;
	else if (token == "*") return true;
	else if (token == "/") return true;
	else if (token == "%") return true;
	else return false;
}
bool Calculator::isNumber(const std::string & token){
	if (token.length() == 1){
		if (isdigit(token[0])){
			return true;
		}
		else return false;
	}
	for (int i = 0; i < (token.length()); i++){
		if (!isdigit(token[i])){
			return false;
		}
	}
	return true;
}
int Calculator::getPrec(const std::string & token){
	if (token == "+") return 2;
	else if (token == "-") return 2;
	else if (token == "/") return 3;
	else if (token == "*") return 3;
	else if (token == "%") return 3;
	else if (token == "(") return 1;
	else return 0;
}
