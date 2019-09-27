//Unary_Expr_Node.cpp

#include "Unary_Expr_Node.h"

Unary_Expr_Node::Unary_Expr_Node(Expr_Node * n2)
	:child_(n2)
{}

Unary_Expr_Node::~Unary_Expr_Node(void){}

int Unary_Expr_Node::eval(void){
	if (this->child_){
		return (-(this->child_->eval()));
	}
}

void Unary_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Unary_Node(*this);
}
