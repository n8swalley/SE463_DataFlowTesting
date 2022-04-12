// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Subtract_Command.h"

Subtract_Command::Subtract_Command(void) : Binary_Operation_Command(), p_(3) { }

Subtract_Command::~Subtract_Command(void){ }

int Subtract_Command::precedence()
{
    return p_;
}

int Subtract_Command::evaluate (int x, int y)
{
    return y - x;
}