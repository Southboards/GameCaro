#include "Headers/Model/AccountList.h"


/*
 * @brief contructor set and get database
 */
AccountList::AccountList()
{
    fstream dataBaseFile;
    string linkBaseFile = "D:/QT/GameCaro/Databases/AccountList.txt";
    if (FileFunction::checkExistAccount(linkBaseFile))
    {
        dataBaseFile.open(linkBaseFile, ios::in |ios::out | ios::app);
        if(dataBaseFile.is_open()==0)
        {
            //// throw
        }
        dataBaseFile.seekg(19);
        string num;
        dataBaseFile >> num;

        this->numAccount = stoi(num);
        dataBaseFile.close();
    }

    else
    {
        dataBaseFile.open(linkBaseFile, ios::in | ios::out | ios::app );
        if(dataBaseFile.is_open()==0)
        {
            //// throw
        }

        string str = "Number of Account: " + FileFunction::getStringNumber(0) + '\n';
        dataBaseFile.seekg(0);
        dataBaseFile << str;
        this->numAccount = 0;
        dataBaseFile.close();
    }

}


/*
 * @brief add new account
 * @param account: string name of account
 */
void AccountList::addAccount(string accountNew, string passWord)
{
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + accountNew + ".ini";
    if (FileFunction::checkExistAccount(linkPlayerFile))
    {
        return;
    }

    /* write account into account list */
    fstream dataBaseFile;
    string linkBaseFile = "D:/QT/GameCaro/Databases/AccountList.txt";

    dataBaseFile.open(linkBaseFile, ios::in | ios::out );
    if(dataBaseFile.is_open()==0 )
    {
        //// throw
        //return;
    }

    dataBaseFile.seekg(0, ios::end);
    dataBaseFile << FileFunction::getStringName(accountNew) << endl;

    dataBaseFile.seekg(19);
    string num;
    dataBaseFile >> num;
    dataBaseFile.seekg(19);
    dataBaseFile << FileFunction::getStringNumber(stoi(num)+1);
    this->numAccount = stoi(num) + 1 ;

    dataBaseFile.close();


    /* create player file */
    fstream playerFile;

    playerFile.open(linkPlayerFile, ios::out );
    if(playerFile.is_open()==0 )
    {
        //// throw
        //return;
    }

    /* 30 bytes for name */
    playerFile << "Player: " << FileFunction::getStringName(accountNew) << endl;
    playerFile << "Password: " ;
    playerFile << FileFunction::getStringName(passWord) << endl;

    /* 48 bytes for info game */
    playerFile << "Win: " << FileFunction::getStringNumber(0) << "   ";               // data 4 byte from 35
    playerFile << "Draw: " << FileFunction::getStringNumber(0) << "   ";              // data 4 byte from 48
    playerFile << "Lose: " << FileFunction::getStringNumber(0) << endl;               // data 4 byte from 61
    playerFile << "Elo: " << FileFunction::getStringNumber(0) << endl;                // data 4 byte from 72

    /* history */
    playerFile << "History Game" << endl;
    playerFile.close();
}



/*
 * @brief sort player rank
 * @return list of player pro to nood
 */
multimap<float, string, greater<float>> AccountList::sortRank()
{
    multimap<float, string, greater<float>> sortList;
    ifstream dataBaseFile;
    string linkBaseFile = "D:/QT/GameCaro/Databases/AccountList.txt";

    dataBaseFile.open(linkBaseFile, ios::in);
    if(dataBaseFile.is_open()==0 )
    {
        //// throw

    }
    dataBaseFile.seekg(19);
    string str;
    dataBaseFile >> str;

    numAccount = stoi(str);

    int pos = 25;
    string account;
    float elo;
    for(int i=0;i<numAccount;i++)
    {
        dataBaseFile.seekg(pos);
        dataBaseFile >> account;
        elo = getElo(account);
        sortList.emplace(elo, account);
        pos += 22;
    }

    dataBaseFile.close();
    return sortList;
}


/*
 * @brief get elo of account
 * @param accout: string name of account
 * @return elo of account
 */
float AccountList::getElo(string account)
{
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + account + ".ini";
    fstream playerFile;
    playerFile.open(linkPlayerFile, ios::in  );
    if(playerFile.is_open()==0 || playerFile.fail())
    {
        //// throw

    }

    playerFile.seekg(104);
    string num;
    playerFile >> num;

    playerFile.close();
    return stof(num);
}


/*
 * @brief get elo of account
 * @param accout: account input
 * @param password: password input
 * @return true if true account and pass
 */
bool AccountList::checkLogin(string account, string password)
{
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + account + ".ini";
    fstream playerFile;
    if (FileFunction::checkExistAccount(linkPlayerFile))
    {
        playerFile.open(linkPlayerFile, ios::in );
        if(playerFile.is_open()==0 || playerFile.fail())
        {
            //// throw

        }

        playerFile.seekg(40);
        string pass;
        playerFile >> pass;

        if (pass == password)
        {
            playerFile.close();
            return 1;
        }
        else
        {
            playerFile.close();
            return 0;
        }

    }

    return 0;
}


/*
 * @brief check existed account
 * @param accout: account input
 * @return true if account existed
 */
bool AccountList::checkAccountExist(string account)
{
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + account + ".ini";
    if (FileFunction::checkExistAccount(linkPlayerFile))
    {
        return 1;
    }
    return 0;

}


