// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Operation_Command.h"

class Multiply_Command : public Binary_Operation_Command
{
    public:
        Multiply_Command (void);

        virtual ~Multiply_Command (void);

        virtual int precedence ();

        virtual int evaluate (int x, int y);
    private:
        const int p_;
};

#endif