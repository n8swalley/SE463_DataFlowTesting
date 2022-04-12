// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Operation_Command.h"

class Add_Command : public Binary_Operation_Command
{
    public:
        Add_Command (void);

        virtual ~Add_Command (void);

        virtual int precedence (void);

        virtual int evaluate (int x, int y);

    private:
        const int p_;
};

#endif