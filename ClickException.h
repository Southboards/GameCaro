#ifndef CLICKEXCEPTION_H
#define CLICKEXCEPTION_H

#include <exception>
using namespace std;

/********************
 * CLASS EXCEPTION
*********************/


class ClickException : public exception
{
    private:

    public:
        const char* what() const throw()
        {
            return "Click Invalid !!!";
        }
};

#endif // CLICKEXCEPTION_H
