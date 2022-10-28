#ifndef SIZEBOARDEXCEPTION_H
#define SIZEBOARDEXCEPTION_H


#include <exception>
using namespace std;

/********************
 * CLASS EXCEPTION
*********************/


class SizeBoardException : public exception
{
    private:

    public:
        const char* what() const throw()
        {
            return "Size of Board Invalid !!!";
        }
};

#endif // SIZEBOARDEXCEPTION_H
