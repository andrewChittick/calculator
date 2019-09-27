//Eval_Expr_Tree.cpp

#include "Eval_Expr_Tree.h"

#include "Expr_Node.h"
#include "Num_Expr_Node.h"
#include "Unary_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Modulus_Expr_Node.h"

Eval_Expr_Tree::Eval_Expr_Tree(void)
	:visitorTree_(),
	valid(true)
{}

Eval_Expr_Tree::~Eval_Expr_Tree(void){}

void Eval_Expr_Tree::Visit_Number_Node(const Num_Expr_Node & node){
	visitorTree_.push(node.number_);
}

void Eval_Expr_Tree::Visit_Unary_Node(const Unary_Expr_Node & node){
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))
  //
  // I fixed this by using the visitor pattern correctly.
	
	node.child_->accept(*this);
	
	int x = visitorTree_.top();
	visitorTree_.pop();
	visitorTree_.push(-x);
}

void Eval_Expr_Tree::Visit_Add_Node(const Add_Expr_Node & node){
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))
  //
  // I fixed this by using the visitor pattern correctly.

	node.left_->accept(*this);
	node.right_->accept(*this);

	int x = visitorTree_.top();
	visitorTree_.pop();
	int y = visitorTree_.top();
	visitorTree_.pop();
	visitorTree_.push(x+y);
}

void Eval_Expr_Tree::Visit_Subtract_Node(const Subtract_Expr_Node & node){
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))
  //
  // I fixed this by using the visitor pattern correctly.
  
	node.left_->accept(*this);
	node.right_->accept(*this);

	int x = visitorTree_.top();
	visitorTree_.pop();
	int y = visitorTree_.top();
	visitorTree_.pop();
	visitorTree_.push(y-x);
}

void Eval_Expr_Tree::Visit_Divide_Node(const Divide_Expr_Node & node){
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))
  //
  // I fixed this by using the visitor pattern correctly.
	 
	node.left_->accept(*this);
	node.right_->accept(*this);

	int x = visitorTree_.top();
	if (x != 0){//check for division by 0
		visitorTree_.pop();
		int y = visitorTree_.top();
		visitorTree_.pop();
		visitorTree_.push(y/x);
	}
	else{
		std::cout<<"divide by 0 error"<<std::endl;
		valid = false;//set flag
	}
}

void Eval_Expr_Tree::Visit_Multiply_Node(const Multiply_Expr_Node & node){
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))
  //
  // I fixed this by using the visitor pattern correctly.
  
	node.left_->accept(*this);
	node.right_->accept(*this);

	int x = visitorTree_.top();
	visitorTree_.pop();
	int y = visitorTree_.top();
	visitorTree_.pop();
	visitorTree_.push(y*x);
}

void Eval_Expr_Tree::Visit_Modulus_Node(const Modulus_Expr_Node & node){
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))
  //
  // I fixed this by using the visitor pattern correctly.
	 	 
	node.left_->accept(*this);
	node.right_->accept(*this);

	int x = visitorTree_.top();
	visitorTree_.pop();
	int y = visitorTree_.top();
	visitorTree_.pop();
	visitorTree_.push(y%x);
}

int Eval_Expr_Tree::result(void) const{
	return (this->visitorTree_.top());
}

bool Eval_Expr_Tree::result_valid(void){
	return (valid);
}
