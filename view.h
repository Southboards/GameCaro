#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include "Windows.h"
#include "../Model/BoardModel.h"
#include "../Model/GameModel.h"
#include "../Invalid/checkinvalid.h"
#include "../Exceptions/ClickException.h"
#include "../Exceptions/SizeBoardException.h"
#include "../Exceptions/CommandException.h"
#include <fstream>
#include "../Model/AccountList.h"



using namespace std;

/**********
 * DEFINE
**********/




/**********
 * API
**********/



class View
{
private:
    Board board;

    /*
     * @brief get event mouse and get position
     */
    bool MouseEventProc(MOUSE_EVENT_RECORD mer, COORD& mouse);
    void GetMousePosWin(COORD& mouse);


    /*
     * @brief set of screen console size
     * @param width: width of screen
     *        height: heght of screen
     */
    void setWindowSize(SHORT width, SHORT height);




    /*
     * @brief goto the poisiton of console
     * @param x: coord x
     * @param y: coord y
     */
    void gotoXY(int x, int y);


    /*
     * @brief clear row
     * @param row: clear this row
     */
    void clearLine(int row);


    /*
     * @brief set color
     * @param color
     */
    void setColor(int color);





public:
    View();

    /*
     * @brief getter board
     * @return data board
     */
    Board getBoard();

    /*
     * @brief screen main
     */
    void screenMenuMain();

    /*
     * @brief screen get command for menu main
     * @param return in this commnad (ref)
     */
    void screenGetCommandMain(int& command);


    /*
     * @brief screen get account and pass
     * @param account (ref)
     * @param password (ref)
     */
    void screenLogin(string& account, string& password);

    /*
     * @brief screen login fail
     */
    void screenLoginFail();


    /*
     * @brief screen get new account and pass
     * @param account (ref)
     * @param password (ref)
     */
    void screenRegister(string& account, string& password);

    /*
     * @brief screen login done
     */
    void screenRegisterDone();

    /*
     * @brief screen for menu login done
     */
    void screenMenuStart();


    /*
     * @brief screen get command in screen start
     * @param return in this commnad (ref)
     */
     void screenGetCommandStart(int& command);


    /*
     * @brief screen set up player
     * @param namePlayer1: name of player 1 (ref)
     *        namePlayer2: name of player 2 (ref)
     */
    void screenSetPlayer(string& namePlayer1, string& namePlayer2);


    /*
     * @brief screen show infomation player
     * @param game: game's info
     */
    void screenInfoGame(Game game);


    /*
     * @brief screen set up board
     */
    void screenGetSizeBoard(int& width, int& height);


    void setBoard(int width, int height);

    /*
     * @brief screen show board
     */
    void screenShowBoard();


    /*
     * @brief draw board game
     */
    void drawBoard();


    /*
     * @brief draw X or O
     * @param X: X if true, 0 if false
     *        pose: pose in board (coord Board)
     */
    void drawMove(bool X, COORD pose);




    /*
     * @brief screen play game
     * @param game: show info this game
     */
    void screenPlayInGame(Game game);


    /*
     * @brief screen show turn
     * @param game: game in play
     *        turn: turn's player
     */
    void screenTurn(Game game, bool turn);

    /*
     * @brief screen show winner overload
     * @param game: game in play
     *        turn: turn's player
     */
    void screenShowEndGame(Game game, bool turn);


    /*
     * @brief screen show draw overload
     */
    void screenShowEndGame();



    /*
     * @brief screen get command in screen replay
     * @param return in this commnad (ref)
     */
    void screenGetCommandReplay(int& command);

     /*
      * @brief get poisiton of mouse click
      * @return coord mouse is click there
      */
    COORD getPositionMouseClick();



     /*
      * @brief transform coord console to coord board
      * @return coord: coord Console
      */
    COORD transCoordConsoleToBoard(COORD pos);

     /*
      * @brief transform coord board to coord console
      * @return coord: coord board
      */
    COORD transCoordBoardToConsole(COORD cell);



    /*
     * @brief screen show player rank
     */
    void screenRank(AccountList list);


    void waitGame();




};

#endif // VIEW_H
