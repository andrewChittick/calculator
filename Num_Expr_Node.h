//Num_Expr_Node.h

#ifndef _NUM_EXPR_NODE_H_
#define _NUM_EXPR_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Num_Expr_Node: public Expr_Node{
	public:
		Num_Expr_Node(int n);
		virtual ~Num_Expr_Node(void);
		virtual int eval(void);
		virtual void accept(Expr_Node_Visitor & v);
	protected:
		friend class Eval_Expr_Tree;
		int number_;
};

#endif
