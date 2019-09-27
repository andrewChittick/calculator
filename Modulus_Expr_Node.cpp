//Module_Expr_Node.cpp

#include "Modulus_Expr_Node.h"

Modulus_Expr_Node::Modulus_Expr_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{}

Modulus_Expr_Node::~Modulus_Expr_Node(void){}

int Modulus_Expr_Node::eval(void){
	return (this->left_->eval() % this->right_->eval());
}

void Modulus_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Modulus_Node(*this);
}
