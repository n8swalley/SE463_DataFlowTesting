// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include "Binary_Operation_Command.h"

Binary_Operation_Command::Binary_Operation_Command (void) : Expr_Command(){}

Binary_Operation_Command::~Binary_Operation_Command (void){}

bool Binary_Operation_Command::execute (std::stack<int> & stack)
{
    if (stack.size() < 2)
        return false;

    int x = stack.top();
    stack.pop();

    int y = stack.top();
    stack.pop();

    stack.push(this->evaluate(x,y));

    return true;
}