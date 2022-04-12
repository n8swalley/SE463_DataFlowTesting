// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Modulus_Command.h"

Modulus_Command::Modulus_Command(void) : Binary_Operation_Command(), p_(2){ }

Modulus_Command::~Modulus_Command(void){ }

int Modulus_Command::precedence()
{
    return p_;
}

int Modulus_Command::evaluate(int x, int y)
{
    if (x == 0)
    {
        std::cout<< "ERROR: cannot mod by 0."<<std::endl;
        throw Mod_By_Zero();
    }

    return y % x;
}