// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Divide_Command.h"

Divide_Command::Divide_Command(void) : Binary_Operation_Command(), p_(2) {}

Divide_Command::~Divide_Command(void){}

int Divide_Command::precedence()
{
    return p_;
}

int Divide_Command::evaluate(int x, int y)
{
    if (x == 0)
    {
        std::cout<< "ERROR: cannot divide by 0." << std::endl;
        throw Divide_By_Zero();
    }
    return y / x;

}