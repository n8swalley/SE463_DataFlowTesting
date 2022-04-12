// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Binary_Operation_Command.h"
#include <exception>

class Modulus_Command : public Binary_Operation_Command
{
    public:
        Modulus_Command (void);

        virtual ~Modulus_Command (void);

        virtual int precedence ();

        virtual int evaluate (int x, int y);

        class Mod_By_Zero : public std::exception {
    public:
        /// Default constructor.
        Mod_By_Zero(void): std::exception() { }
    };

    private:
        const int p_;
};

#endif