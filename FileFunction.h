#ifndef FILEFUNCTION_H
#define FILEFUNCTION_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/**********
 * API
**********/

class FileFunction
{
public:
    FileFunction();

    /*
     * @brief get size of file
     * @param link: link of file
     */
    static int getFileSize(string link);



    /*
     * @brief stran int to string 4 char
     * @param num: int num
     * @return 4 char of number
     */
    static string getStringNumber(int num);

    /*
     * @brief stran float to string 4 char
     * @param num: float num
     * @return 4 char of number
     */
    static string getStringNumber(float num);

    /*
     * @brief check existed account
     * @param link: link of account
     * @return true if account existed
     */
    static bool checkExistAccount(string link);



    /*
     * @brief get string name fill 20 char
     * @param name: name of account
     * @return string name 20 char
     */
    static string getStringName(string name);

};

#endif // FILEFUNCTION_H
