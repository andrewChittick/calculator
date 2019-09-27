//Subtract_Expr_Node.cpp

#include "Subtract_Expr_Node.h"

Subtract_Expr_Node::Subtract_Expr_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{}

Subtract_Expr_Node::~Subtract_Expr_Node(void){}

int Subtract_Expr_Node::eval(){
	return (this->left_->eval() - this->right_->eval());
}

void Subtract_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Subtract_Node(*this);
}
