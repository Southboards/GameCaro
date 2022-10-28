#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <map>
#include "../Controller/FileFunction.h"

using namespace std;

/**********
 * API
**********/

class AccountList
{
private:
    int numAccount ;

public:
    AccountList();

    /*
     * @brief add new account
     * @param account: string name of account
     */
    void addAccount(string account, string passWord);


    /*
     * @brief sort player rank
     * @return list of player pro to nood
     */
    multimap<float, string, greater<float>> sortRank();


    /*
     * @brief get elo of account
     * @param accout: string name of account
     * @return elo of account
     */
    float getElo(string account);


    /*
     * @brief get elo of account
     * @param accout: account input
     * @param password: password input
     * @return true if true account and pass
     */
    bool checkLogin(string account, string password);


    /*
     * @brief check existed account
     * @param accout: account input
     * @return true if account existed
     */
    bool checkAccountExist(string account);



};

#endif // ACCOUNTLIST_H
