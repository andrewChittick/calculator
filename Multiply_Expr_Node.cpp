//Multiply_Expr_Node.cpp

#include "Multiply_Expr_Node.h"

Multiply_Expr_Node::Multiply_Expr_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{}

Multiply_Expr_Node::~Multiply_Expr_Node(void){}

int Multiply_Expr_Node::eval(void){
	return (this->left_->eval() * this->right_->eval());
}

void Multiply_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Multiply_Node(*this);
}
