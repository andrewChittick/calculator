//Expr_Tree.cpp

#include "Expr_Tree.h"

Expr_Tree::Expr_Tree(void)
	:root_()
{}

void Expr_Tree::push(Expr_Node * en){
	root_.push(en);
}

Expr_Node* Expr_Tree::top(void){
	return(this->root_.top());
}

Expr_Node* Expr_Tree::pop(void){
	Expr_Node * en = this->root_.top();
	this->root_.pop();
	return(en);
}

bool Expr_Tree::is_empty(void){
	return(this->root_.is_empty());
}
