//Add_Expr_Node.cpp

#include "Add_Expr_Node.h"

Add_Expr_Node::Add_Expr_Node(Expr_Node * n1, Expr_Node * n2)
	:Binary_Expr_Node(n1, n2)
{}

Add_Expr_Node::~Add_Expr_Node(void){}

int Add_Expr_Node::eval(void){
	return (this->left_->eval() + this->right_->eval());
}

void Add_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Add_Node(*this);
}
