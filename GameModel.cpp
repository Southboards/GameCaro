#include "Headers/Model/GameModel.h"

Game::Game()
{

}

Game::Game(Player player1, Player player2 )
{
    this->player1 = player1;
    this->player2 = player2; 
    setupDataPlayer(this->player1);
    setupDataPlayer(this->player2);
}



/*
 * @brief get player
 * @retrun this player
 */
Player Game::getPlayerGame(bool player)
{
    if (player==PLAYER_1)
    {
        return player1;
    }
    else
    {
        return player2;
    }
}

/*
 * @brief get history move of player
 * @param player: numberPlayer player1 or player2
 */
vector<COORD> Game::getMovePlayer(bool player)
{
    if (player==PLAYER_1)
    {
        return movePlayer1;
    }
    else
    {
        return movePlayer2;
    }
}


/*
 * @brief add 1 move for 1 player
 * @param move: move of player
 *        player: this player moved (player1 or player2)
 */
void Game::addMove(COORD move, bool player)
{
    if (player==PLAYER_1)
    {
        movePlayer1.push_back(move);
    }
    else
    {
        movePlayer2.push_back(move);
    }
}

/*
 * @brief add 1 game win and 1 lose for other player and update database
 * @param player: this player winner
 */
void Game::updateDataGame(bool player)
{
    if (player == PLAYER_1)
    { 
        player1.setNumWins(player1.getNumWins()+1);
        player2.setNumLoses(player2.getNumLoses()+1);

    }
    else
    {
        player2.setNumWins(player2.getNumWins()+1);
        player1.setNumLoses(player1.getNumLoses()+1);
    }
    updateDataPlayer();
}


/*
 * @brief add 1 game draw for 2 player and update database
 */
void Game::updateDataGame()
{
    player1.setNumDraws(player1.getNumDraws()+1);
    player2.setNumDraws(player2.getNumDraws()+1);
    updateDataPlayer();
}


/*
 * @brief reset history move
 */
void Game::resetMove()
{
    movePlayer1.clear();
    movePlayer2.clear();
}


/*
 * @brief check file exist and create file data player
 * @param player: this player
 */
void Game::setupDataPlayer(Player& player)
{
    ifstream playerFile;
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + player.getName() + ".ini";

    /* check file */
    if (FileFunction::checkExistAccount(linkPlayerFile)==0)
    {
        return;
    }

    /* stran file - user existed*/
    else
    {
        playerFile.open(linkPlayerFile, ios::in);
        if(playerFile.is_open()==0 || playerFile.fail())
        {
            //// throw
        }

        /* get win number */
        playerFile.seekg(67);
        string win_str ;
        playerFile >> win_str;
        int win = stoi(win_str) ;

        /* get draw number */
        playerFile.seekg(80);
        string draw_str ;
        playerFile >> draw_str;
        int draw = stoi(draw_str) ;

        /* get lose number */
        playerFile.seekg(93);
        string lose_str ;
        playerFile >> lose_str;
        int lose = stoi(lose_str) ;


        player.setNumWins(win);                     // data 4 byte from 35
        player.setNumDraws(draw);                   // data 4 byte from 48
        player.setNumLoses(lose);                   // data 4 byte from 61

        playerFile.close();
    }
}


/*
 * @brief write data game into database
 * @param game: this game player play
 */
void Game::updateDataPlayer()
{
    writeDataPlayer(player1);
    writeDataPlayer(player2);
    writeHistoryGame(player1);
    writeHistoryGame(player2);
}

/*
 * @brief write data player into database
 * @param game: this game player play
 * @param player: this player
 */
void Game::writeDataPlayer(Player player)
{
    fstream playerFile;
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + player.getName() + ".ini";

    playerFile.open(linkPlayerFile, ios::out | ios::in );
    if(playerFile.is_open()==0 || playerFile.fail())
    {
        //// throw
    }

    playerFile.seekg(67);
    playerFile << FileFunction::getStringNumber(player.getNumWins()) ;           // data 4 byte from 35
    playerFile.seekg(80);
    playerFile << FileFunction::getStringNumber(player.getNumDraws());           // data 4 byte from 48
    playerFile.seekg(93);
    playerFile << FileFunction::getStringNumber(player.getNumLoses());           // data 4 byte from 61
    playerFile.seekg(104);
    playerFile << FileFunction::getStringNumber(player.getEloPlayer());         // data 4 byte from 72

    playerFile.close();

}



/*
 * @brief write history move 2 player to database
 * @param player: player to account
 */
void Game::writeHistoryGame(Player player)
{
    fstream playerFile;
    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + player.getName() + ".ini";

    playerFile.open(linkPlayerFile, ios::out | ios::in | ios::app );
    if(playerFile.is_open()==0 || playerFile.fail())
    {
        //// throw
    }

    int sumMove = (int)movePlayer1.size() + (int)movePlayer2.size();

    /* Line general info */
    playerFile << __DATE__ << endl;
    playerFile << FileFunction::getStringName(player1.getName());
    playerFile << " vs ";
    playerFile << FileFunction::getStringName(player2.getName());
    playerFile << endl;

    /* Line winner */
    playerFile << "Winner: ";

    if (sumMove%2==1)
    {
        playerFile << FileFunction::getStringName(player1.getName());
    }
    else
    {
        playerFile << FileFunction::getStringName(player2.getName());
    }
    playerFile << endl;

    /* Line board*/
    playerFile << "Board: ";
    playerFile << FileFunction::getStringNumber(30);    /// NOT DONE
    playerFile << " x ";
    playerFile << FileFunction::getStringNumber(15);    /// NOT DONE
    playerFile << endl;

    /* Line move */
    playerFile << "List Move: ";

    playerFile << FileFunction::getStringNumber(sumMove);
    playerFile << endl;

    int i=0;
    while ( i<(int)movePlayer1.size() || i<(int)movePlayer2.size())
    {
        if (i<(int)movePlayer1.size())
        {
            playerFile << FileFunction::getStringNumber(movePlayer1[i].X) + " ";
            playerFile << FileFunction::getStringNumber(movePlayer1[i].Y) + " ";
        }
        if (i<(int)movePlayer2.size())
        {
            playerFile << FileFunction::getStringNumber(movePlayer2[i].X) + " ";
            playerFile << FileFunction::getStringNumber(movePlayer2[i].Y) + " ";
        }
        i++;

    }
    playerFile << endl;

    playerFile.close();
}


