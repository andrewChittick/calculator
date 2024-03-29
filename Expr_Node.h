//Expr_Node.h

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

class Expr_Node_Visitor;

class Expr_Node{
	public:
		Expr_Node(void);
		virtual ~Expr_Node(void);

		//used to traverse the tree
		virtual void accept (Expr_Node_Visitor & v) = 0;
		virtual int eval (void) = 0;
};

#endif
