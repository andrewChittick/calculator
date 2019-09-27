//Unary_Expr_Node.h

#ifndef _UNARY_EXPR_NODE_H_
#define _UNARY_EXPR_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Unary_Expr_Node: public Expr_Node{
	public:
		Unary_Expr_Node(Expr_Node * n2);
		virtual ~Unary_Expr_Node(void);
		virtual int eval(void);
		virtual void accept(Expr_Node_Visitor & v);
	protected:
		friend class Eval_Expr_Tree;
		Expr_Node * child_;
};

#endif
