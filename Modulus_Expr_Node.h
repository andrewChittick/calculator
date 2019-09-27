//Modulus_Expr_Node.h

#ifndef _MODULUS_EXPR_NODE_H_
#define _MODULUS_EXPR_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Modulus_Expr_Node: public Binary_Expr_Node{
	public:
		Modulus_Expr_Node(Expr_Node *n1, Expr_Node *n2);
		virtual ~Modulus_Expr_Node(void);
		virtual int eval(void);
		virtual void accept(Expr_Node_Visitor & v);
};

#endif
