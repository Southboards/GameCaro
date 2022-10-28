#ifndef NAMEEXCEPTION_H
#define NAMEEXCEPTION_H

#include <exception>
using namespace std;

/********************
 * CLASS EXCEPTION
*********************/


class NameException : public exception
{
    private:

    public:
        const char* what() const throw()
        {
            return "Name Invalid !!!";
        }
};


#endif // NAMEEXCEPTION_H
