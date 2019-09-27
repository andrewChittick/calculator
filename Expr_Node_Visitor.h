//Expr_Node_Visitor.h

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

#include "Expr_Node.h"
class Expr_Node;
class Num_Expr_Node;
class Unary_Expr_Node;
class Add_Expr_Node;
class Subtract_Expr_Node;
class Divide_Expr_Node;
class Multiply_Expr_Node;
class Modulus_Expr_Node;

class Expr_Node_Visitor{
	public:
		virtual ~Expr_Node_Visitor(void);
		//methods for visiting concrete nodes
		virtual void Visit_Number_Node (const Num_Expr_Node & node) = 0;
		virtual void Visit_Unary_Node (const Unary_Expr_Node & node) = 0;
		virtual void Visit_Add_Node (const Add_Expr_Node & node) = 0;
		virtual void Visit_Subtract_Node (const Subtract_Expr_Node & node) = 0;
		virtual void Visit_Divide_Node (const Divide_Expr_Node & node) = 0;
		virtual void Visit_Multiply_Node (const Multiply_Expr_Node & node) = 0;
		virtual void Visit_Modulus_Node (const Modulus_Expr_Node & node) = 0;
	protected:
		Expr_Node_Visitor(void);
};

#endif
