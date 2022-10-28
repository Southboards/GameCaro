#include "Headers/Model/PlayerModel.h"

Player::Player()
{

}


Player::Player(string name)
{
    this->name = name;
    this->numWins = 0;
    this->numDraws = 0;
    this->numLoses = 0;
}

/*
 * @brief set name of player
 * @param name: name of player
 */
void Player::setName(string name)
{
    this->name = name;
}

/*
 * @brief set number of win game
 * @param num: number of win game
 */
void Player::setNumWins(int num)
{
    numWins = num;
}

/*
 * @brief set number of draw game
 * @param num: number of draw game
 */
void Player::setNumDraws(int num)
{
    numDraws = num;
}

/*
 * @brief set number of lose game
 * @param num: number of lose game
 */
void Player::setNumLoses(int num)
{
    numLoses = num;
}


/*
 * @brief get name of player
 * @return name of player
 */
string Player::getName()
{
    return name;
}

/*
 * @brief get number of win game
 * @return number of win game
 */
int Player::getNumWins()
{
    return numWins;
}

/*
 * @brief get number of draw game
 * @return number of draw game
 */
int Player::getNumDraws()
{
    return numDraws;
}

/*
 * @brief get number of lose game
 * @return number of lose game
 */
int Player::getNumLoses()
{
    return numLoses;
}


/*
 * @brief cal elo player
 */
float Player::getEloPlayer()
{
    float elo;
    if (getNumLoses()==0)
    {
        elo =  (float)getNumWins();
    }
    else
    {
        elo = (float)getNumWins() / (float)getNumLoses();
    }
    return elo;
}


