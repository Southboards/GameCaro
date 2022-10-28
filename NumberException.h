#ifndef NUMBEREXCEPTION_H
#define NUMBEREXCEPTION_H


#include <exception>
using namespace std;

/********************
 * CLASS EXCEPTION
*********************/


class NumberException : public exception
{
    private:

    public:
        const char* what() const throw()
        {
            return "Number Invalid !!!";
        }
};


#endif // NUMBEREXCEPTION_H
