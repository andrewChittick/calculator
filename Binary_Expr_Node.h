//Binary_Expr_Node.h

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node: public Expr_Node{
	public:
		Binary_Expr_Node(Expr_Node * n1, Expr_Node * n2);
		virtual ~Binary_Expr_Node(void);
		virtual int eval(void) = 0;
		virtual void accept(Expr_Node_Visitor & v) = 0;
	protected:
		friend class Eval_Expr_Tree;
		Expr_Node *right_;
		Expr_Node *left_;
};

#endif
