//Expr_Tree_Builder.h

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Num_Expr_Node.h"
#include "Unary_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulus_Expr_Node.h"

class Expr_Tree_Builder: public Expr_Builder{
	public:
		Expr_Tree_Builder(void);
		virtual ~Expr_Tree_Builder(void);
		virtual void start_expression(void);
		virtual void build_num_operator(int n);
		virtual void build_add_operator(void);
		virtual void build_subtract_operator(void);
		virtual void build_multiply_operator(void);
		virtual void build_divide_operator(void);
		virtual void build_modulus_operator(void);
		Expr_Node * get_expression(void);
	private:
		//current state of expression tree
		Expr_Tree * tree_;
};

#endif
