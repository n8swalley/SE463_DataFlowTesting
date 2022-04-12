// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Number_Command.h"

Number_Command::Number_Command () : Expr_Command(), p_(0), number_(0) { }

Number_Command::Number_Command (int number) : p_(0), number_(number){ }

Number_Command::~Number_Command() { }

bool Number_Command::execute(std::stack<int> &stack)
{
    stack.push(this->number_);
    return true;
}

int Number_Command::precedence()
{
    return p_;
}