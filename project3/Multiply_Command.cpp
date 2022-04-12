// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Multiply_Command.h"

Multiply_Command::Multiply_Command() : Binary_Operation_Command(), p_(2) { }

Multiply_Command::~Multiply_Command() { }

int Multiply_Command::precedence()
{
    return p_;
}

int Multiply_Command::evaluate(int x, int y)
{
    return y * x;
}