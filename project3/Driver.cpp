// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <array>
#include <sstream>
#include <string>
#include "Expr_Command.h"
#include "Stack_Expr_Command_Factory.h"

// cmdStr is used by: cmdHelper(), parenthesisHelper(), and main() 
std::string cmdStr("");

// input is used by: parenthesisHelper(), cleanup(), and main()
std::stringstream * input = new std::stringstream();

// Dr. Ryan: Be careful - you are on the verge of parameter paralysis.
// FIXED: made input string stuff global to lighten up parameter usage

void infixToPostfix(std::stack<Expr_Command*> &cmdStack, std::stack<Expr_Command *> &pStack);


bool cmdHelper(std::stack<Expr_Command*> &cmdStack, std::stack<Expr_Command*> &pStack,  Expr_Command *cmd, Expr_Command_Factory *factory);


void cleanup (std::stack<Expr_Command*> &cmdStack, std::stack<Expr_Command*> &pStack, Expr_Command_Factory *factory);


bool parenthesisHelper(Expr_Command *cmd, Expr_Command_Factory *factory, std::stack<Expr_Command*> &pStack);


int main (int argc, char * argv [])
{
    // string stream stuff
    std::string inputStr("");

    // abstract factory Stuff
    Expr_Command_Factory * factory = new Stack_Expr_Command_Factory();
    Expr_Command * cmd = nullptr;

    // stack stuff
    std::stack <Expr_Command *> cmdStack;
    std::stack <Expr_Command *> pStack;

    std::cout << "\n # # # WELCOME TO THE INFIX-POSTFIX CALCULATOR # # #\n";

    while (true)
    {
        std::cout<<"\nPlease enter the infix expression to evaluate (spaces between all characters)\n";  
        std::cout<<"Type QUIT to exit the program.\n"<<std::endl;
        std::cout<<"Expression: ";	

        getline(std::cin, inputStr);

        input->clear();
        input->str("");

        *input << inputStr;

        while(getline(*input, cmdStr, ' ')) // space delimited
        {
            if (cmdStr == "(")
            {
                if(!parenthesisHelper(cmd, factory, pStack))
                {
                    cleanup(cmdStack, pStack, factory);
                    return 0;
                }
            }
            else if (!cmdHelper(cmdStack, pStack, cmd, factory))
            {
                cleanup(cmdStack, pStack, factory);
                return 0;
            }
        }
        infixToPostfix(cmdStack, pStack);
    }
    cleanup(cmdStack, pStack, factory);
    return 0;
}

void infixToPostfix(std::stack<Expr_Command *> & cmdStack, std::stack<Expr_Command *> & pStack)
{
    int result(0);
    while(!cmdStack.empty())
        {
            pStack.push(cmdStack.top());
            cmdStack.pop();
        }

        while(!pStack.empty())
        {
            cmdStack.push(pStack.top());
            pStack.pop();
        }
        
        std::stack<int> nStack;
        while(!cmdStack.empty())
        {
            try
            {
                cmdStack.top()->execute(nStack);
                delete cmdStack.top();
                cmdStack.pop();
            }
            catch (const Divide_Command::Divide_By_Zero & e)
            {
                std::cout<< "Please enter a valid division command\n";
            }
            catch (const Modulus_Command::Mod_By_Zero & e)
            {
                std::cout<< "Please enter a valid modulus command\n";
            }
            catch(std::invalid_argument)
            {
                std::cout<<"ERROR 00: invalid argument: "<<std::endl;
                while(!cmdStack.empty())
                {
                    delete cmdStack.top();
                    cmdStack.pop();
                }
                nStack = { }; // weird way to clear the stack in case a num is left
            }
        }

        if (nStack.size() == 1)
        {
            result = nStack.top();
            std::cout<<"\nRESULT = " << result << std::endl;
        }
        else // deals with empty input expression
        {
            std::cout <<"ERROR 01: invalid input\n";
        }
}

bool cmdHelper(std::stack<Expr_Command*> &cmdStack, std::stack<Expr_Command*> &pStack,  Expr_Command *cmd, Expr_Command_Factory *factory)
{
    if (cmdStr == "+")
    {
        cmd = factory->create_add_command(); 
    }
    else if (cmdStr == "-")
    {
        cmd = factory->create_subtract_command();
    }
    else if (cmdStr == "*")
    {
        cmd = factory->create_multiply_command();
    }
    else if (cmdStr == "/")
    {
        cmd = factory->create_divide_command();
    }
    else if (cmdStr == "%")
    {
        cmd = factory->create_modulus_command();
    }
    else if (cmdStr == "QUIT")
    {
        std::cout<<"\n # # # GOODBYE! # # #\n";
        return false;
    }
    else
    {
        int num(0);
        try
        {
            num = stoi(cmdStr);
        }
        catch(std::invalid_argument)
        {
            std::cout<<"ERROR 02: invalid input\n";
            return false;
        }
        cmd = factory->create_number_command(num);
    }
    if (cmd->precedence() == 0) // num command
    {
        pStack.push(cmd);
    }
    else if(cmdStack.empty() || cmdStack.top()->precedence() > cmd->precedence())
    {
        cmdStack.push(cmd);
    }

    else
    {
        pStack.push(cmdStack.top());
        cmdStack.pop();
        cmdStack.push(cmd);
    }
    return true;
}

bool parenthesisHelper(Expr_Command *cmd, Expr_Command_Factory *factory, std::stack<Expr_Command*> &pStack)
{
    std::stack<Expr_Command *> temp;

    while(getline(*input, cmdStr, ' ') && cmdStr != ")")
    {
        if(cmdStr == "(")
        {
            if(!parenthesisHelper(cmd, factory, pStack))
            {
                std::cout<<"ERROR 03: invalid input"<<std::endl;
                return false; 
            }
        }
        else if(!cmdHelper(temp, pStack, cmd, factory))
        {
            std::cout<<"ERROR 04: invalid input"<<std::endl;
            return false;
        }
    }

    if(cmdStr != ")")
    {
        std::cout<<"ERROR 05: invalid input\n";
        return false;
    }

    while(!temp.empty())
    {
        pStack.push(temp.top());
        temp.pop();
    }

    return true;
}

void cleanup(std::stack<Expr_Command *> &cmdStack, std::stack<Expr_Command *> &pStack, Expr_Command_Factory *factory)
{
    while(!cmdStack.empty())
    {
        delete cmdStack.top();
        cmdStack.pop();
    }
    while(!pStack.empty())
    {
        delete pStack.top();
        pStack.pop();
    }
    delete factory;
    delete input;
}
