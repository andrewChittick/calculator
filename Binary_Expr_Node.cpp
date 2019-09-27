//Binary_Expr_Node.cpp


#include "Binary_Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node(Expr_Node * n1, Expr_Node * n2)
	:left_(n1),
	right_(n2)
{}

Binary_Expr_Node::~Binary_Expr_Node(void){}

