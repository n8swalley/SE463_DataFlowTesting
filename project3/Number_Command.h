// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley
#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"

class Number_Command : public Expr_Command
{
    public:

        Number_Command (void);

        Number_Command (int number);

        ~Number_Command (void);

        virtual int precedence();

        virtual bool execute (std::stack<int> &stack);

    private:

        int number_;
        const int p_;

};

#endif