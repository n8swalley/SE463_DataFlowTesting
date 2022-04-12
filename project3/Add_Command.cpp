// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Add_Command.h"

// Dr. Ryan: We should really use a global constant in place of the (3).
Add_Command::Add_Command (void) : Binary_Operation_Command(), p_(3) { }

Add_Command::~Add_Command (void){ }

int Add_Command::precedence()
{
    return p_;
}

int Add_Command::evaluate (int x, int y)
{
    return y + x;
}