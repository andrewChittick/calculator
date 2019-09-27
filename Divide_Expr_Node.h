//Divide_Expr_Node.h

#ifndef _DIVIDE_EXPR_NODE_H_
#define _DIVIDE_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

#include "Expr_Node_Visitor.h"

class Divide_Expr_Node: public Binary_Expr_Node{
	public:
		Divide_Expr_Node(Expr_Node *n1, Expr_Node *n2);
		virtual ~Divide_Expr_Node(void);
		virtual int eval();
		virtual void accept(Expr_Node_Visitor & v);
};

#endif
