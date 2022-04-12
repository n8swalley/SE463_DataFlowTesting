// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Operation_Command.h"
#include <exception>

class Divide_Command : public Binary_Operation_Command
{
    public:
        Divide_Command (void);

        virtual ~Divide_Command (void);

        virtual int precedence ();

        virtual int evaluate (int x, int y);

        class Divide_By_Zero : public std::exception {
    public:
        /// Default constructor.
        Divide_By_Zero(void): std::exception() { }
    };

    private:
        const int p_;
};

#endif