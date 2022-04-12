// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _BINARY_OPERATION_COMMAND_H_
#define _BINARY_OPERATION_COMMAND_H_

#include "Expr_Command.h"

class Binary_Operation_Command : public Expr_Command
{
    public:

        Binary_Operation_Command (void);

        virtual ~Binary_Operation_Command (void);

        virtual int precedence(void) = 0;

        virtual int evaluate (int x, int y) = 0;

        virtual bool execute (std::stack<int> &stack);
};

#endif

