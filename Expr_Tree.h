//Expr_Tree.h

#ifndef _EXPR_TREE_H_
#define _EXPR_TREE_H_

#include "Expr_Node.h"
#include "Stack.h"

class Expr_Tree{
	public:
		Expr_Tree(void);
		void push(Expr_Node* en);
		Expr_Node* top(void);
		Expr_Node* pop(void);
		bool is_empty(void);
	protected:
		Stack <Expr_Node*> root_;
};

#endif
