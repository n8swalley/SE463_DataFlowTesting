// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
    public:

        Stack_Expr_Command_Factory (void);
        virtual ~Stack_Expr_Command_Factory (void);
        virtual Number_Command * create_number_command (int number);
        virtual Add_Command * create_add_command (void);
        virtual Subtract_Command * create_subtract_command (void);
        virtual Modulus_Command * create_modulus_command (void);
        virtual Multiply_Command * create_multiply_command (void);
        virtual Divide_Command * create_divide_command (void);

};

#endif