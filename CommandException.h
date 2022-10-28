#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <exception>
using namespace std;

/********************
 * CLASS EXCEPTION
*********************/


class CommandException : public exception
{
    private:

    public:
        const char* what() const throw()
        {
            return "Command Invalid !!!";
        }
};


#endif // COMMANDEXCEPTION_H
