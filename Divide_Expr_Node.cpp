//Divide_Expr_Node.cpp

#include "Divide_Expr_Node.h"

Divide_Expr_Node::Divide_Expr_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{}

Divide_Expr_Node::~Divide_Expr_Node(void){}

int Divide_Expr_Node::eval(void){
  // COMMENT You are not handling divide by 0.
  //
  // I fixed this by handling divide by 0 in Eval_Expr_Tree.cpp
	return (this->left_->eval() / this->right_->eval());
}

void Divide_Expr_Node::accept(Expr_Node_Visitor & v){
	v.Visit_Divide_Node(*this);
}
