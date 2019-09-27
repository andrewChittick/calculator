//Expr_Tree_Builder.cpp

#include "Expr_Tree_Builder.h"
#include <iostream>

Expr_Tree_Builder::Expr_Tree_Builder(void)
	:Expr_Builder()
{}

Expr_Tree_Builder::~Expr_Tree_Builder(void){}

void Expr_Tree_Builder::start_expression(void){
	this->tree_ = new Expr_Tree();
}

Expr_Node* Expr_Tree_Builder::get_expression(void){
	return (this->tree_->pop());
}

void Expr_Tree_Builder::build_num_operator(int n){
	Expr_Node * en = new Num_Expr_Node(n);
	this->tree_->push(en);
}

void Expr_Tree_Builder::build_add_operator(void){
	Expr_Node * n2 = this->tree_->pop();
	Expr_Node * n1 = this->tree_->pop();
	Expr_Node * en = new Add_Expr_Node(n1, n2);
	this->tree_->push(en);
}

void Expr_Tree_Builder::build_subtract_operator(void){
	Expr_Node * n2 = this->tree_->pop();
	if (tree_->is_empty()){//unary
		Expr_Node * en = new Unary_Expr_Node(n2);
		this->tree_->push(en);
	}
	else{
		Expr_Node * n1 = this->tree_->pop();
		Expr_Node * en = new Subtract_Expr_Node(n1, n2);
		this->tree_->push(en);
	}
}

void Expr_Tree_Builder::build_multiply_operator(void){
	Expr_Node * n2 = this->tree_->pop();
	Expr_Node * n1 = this->tree_->pop();
	Expr_Node * en = new Multiply_Expr_Node(n1, n2);
	this->tree_->push(en);
}

void Expr_Tree_Builder::build_divide_operator(void){
	Expr_Node * n2 = this->tree_->pop();
	Expr_Node * n1 = this->tree_->pop();
	Expr_Node * en = new Divide_Expr_Node(n1, n2);
	this->tree_->push(en);
}

void Expr_Tree_Builder::build_modulus_operator(void){
	Expr_Node * n2 = this->tree_->pop();
	Expr_Node * n1 = this->tree_->pop();
	Expr_Node * en = new Modulus_Expr_Node(n1, n2);
	this->tree_->push(en);
}
