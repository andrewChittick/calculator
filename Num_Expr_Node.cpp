//Num_Expr_Node.cpp

#include "Num_Expr_Node.h"

Num_Expr_Node::Num_Expr_Node(int n)
	:number_(n)
{}

Num_Expr_Node::~Num_Expr_Node(void){}

void Num_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Number_Node(*this);
}

int Num_Expr_Node::eval(void){
	return (this->number_);
}
