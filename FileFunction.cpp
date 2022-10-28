#include "Headers/Controller/FileFunction.h"

FileFunction::FileFunction()
{

}

/*
 * @brief get size of file
 * @param link: link of file
 */
int FileFunction::getFileSize(string link)
{
    ifstream file;
    file.open(link, ios_base::binary);
    file.seekg(0,ios_base::end);
    int size = file.tellg();
    file.close();
    return size;
}


string FileFunction::getStringName(string name)
{
    string str = name;
    for (int i=0;i<(20-name.length());i++)
    {
        str += " ";
    }
    return str;
}



/*
 * @brief stran int to string 4 char
 * @param num: int num
 * @return 4 char of number
 */
string FileFunction::getStringNumber(int num)
{
    string str = to_string(num);
    for (int i=0;str.length()<4;i++)
    {
        str += ' ';
    }
    return str;
}

/*
 * @brief stran float to string 4 char
 * @param num: float num
 * @return 4 char of number
 */
string FileFunction::getStringNumber(float num)
{
    string str = to_string(num);
    for (int i=4;i<str.length();i++)
    {
        str.erase(i);
    }

    if (str[3]=='.')
    {
        str[3] = ' ';
    }
    return str;
}


/*
 * @brief check existed account
 * @param link: link of account
 * @return true if account existed
 */
bool FileFunction::checkExistAccount(string link)
{
    fstream datafile;;
    datafile.open(link, ios::in);
    if(datafile.is_open()==0 || datafile.fail())
    {
        return 0;
    }
    datafile.close();
    return 1;
}
