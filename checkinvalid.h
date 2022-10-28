#ifndef CHECKINVALID_H
#define CHECKINVALID_H

#include "iostream"
#include "windows.h"
#include <string>
#include "../Exceptions/ClickException.h"
#include "../Exceptions/NumberException.h"
#include "../Exceptions/SizeBoardException.h"
#include "../Exceptions/CommandException.h"
#include "../Exceptions/NameException.h"
#include "../Model/BoardModel.h"



using namespace std;

/**********
 * DIFINE
**********/
#define MAX_SIZE_BOARD_X 30U
#define MAX_SIZE_BOARD_Y 15U
#define MIN_SIZE_BOARD_X 5U
#define MIN_SIZE_BOARD_Y 5U



/**********
 * API
**********/

class checkInvalid
{
public:
    checkInvalid();


    /*
     * @brief check invalid click on
     * @param board: board in check
     *        posClick: posittion click (coord board)
     */
    static void checkInvalidClick(Board board, COORD posClick);


    /*
     * @brief check invalid click on wall board
     * @param posClick: posittion click (coord console)
     */
    static void checkInvalidClick(COORD posClick);


    /*
     * @brief check invalid input is integer ?
     * @param str: string input
     */
    static void checkInvalidInteger(string str);



    /*
     * @brief check invalid input size of board
     * @param width: width of board ( 5<width<30 )
     *        height: height of board ( 5<height<15 )
     */
    static void checkInvalidSizeBoard(string width_str, string height_str);


    /*
     * @brief check input is 1 or 2 or 3
     * @param str: string input
     */
    static void checkInvalidCommandMain(string str);

    /*
     * @brief check input is 1 or 2
     * @param str: string input
     */
    static void checkInvalidCommandReplay(string str);


    /*
     * @brief check name input (0<len<20)
     * @param str: string input
     */
    static void checkInvalidName(string str);


    static void checkInvalidPassWordAccount(string account, string password);



};

#endif // CHECKINVALID_H
