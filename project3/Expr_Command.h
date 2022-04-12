// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include <iostream>
#include <stack>

// PURE ABSTRACT CLASS

class Expr_Command 
{
    public:
        Expr_Command(void) {}
        virtual ~Expr_Command(void) {}
        virtual bool execute (std::stack<int> & stack) = 0;
        virtual int precedence() = 0;
};

#endif