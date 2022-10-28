#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <iostream>
#include <string.h>

using namespace std;



/**********
 * API
**********/

class Player
{
private:
    string name;
    int numWins;
    int numDraws;
    int numLoses;

public:
    Player();
    Player(string name);

    /*
     * @brief set name of player
     * @param name: name of player
     */
    void setName(string name);

    /*
     * @brief set number of win game
     * @param num: number of win game
     */
    void setNumWins(int num);


    /*
     * @brief set number of draw game
     * @param num: number of draw game
     */
    void setNumDraws(int num);


    /*
     * @brief set number of lose game
     * @param num: number of lose game
     */
    void setNumLoses(int num);

    /*
     * @brief get name of player
     * @return name of player
     */
    string getName();

    /*
     * @brief get number of win game
     * @return number of win game
     */
    int getNumWins();


    /*
     * @brief get number of draw game
     * @return number of draw game
     */
    int getNumDraws();

    /*
     * @brief get number of lose game
     * @return number of lose game
     */
    int getNumLoses();

    /*
     * @brief cal elo player
     */
    float getEloPlayer();


};

#endif // PLAYERMODEL_H
