#include "Headers/Invalid/checkinvalid.h"

checkInvalid::checkInvalid()
{

}





/*
 * @brief check invalid click on
 * @param board: board in check
 *        posClick: posittion click (coord board)
 */
void checkInvalid::checkInvalidClick(Board board, COORD posClick)
{

    /* Click on out board */
    if (posClick.X >= board.getWidth() || posClick.Y >= board.getHeight()
          || posClick.X < 0 || posClick.Y < 0 )
    {
        throw ClickException();
    }



    /* Click on cell have data */
    if (board.getBoard()[posClick.Y][posClick.X] == 1)
    {
        throw ClickException();
    }

}



/*
 * @brief check invalid click on wall board
 * @param posClick: posittion click (coord console)
 */
void checkInvalid::checkInvalidClick(COORD posClick)
{
    /* Click on wall board */
    if(posClick.X%4==0 || posClick.Y%2==1)
    {
        throw ClickException();
    }
}



/*
 * @brief check if invalid input is integer or not
 * @param str: string input
 */
void checkInvalid::checkInvalidInteger(string str)
{
    /* Check if first character is '-' or not */
    if (str.length()==0 || (!isdigit(str[0]) && str[0]!= '-' ))
    {
        throw NumberException();
    }

    for (int i = 1; i < str.length(); i++)
    {
        /* Check if character is a number or not */
        if (!isdigit(str[i]))
        {
           throw NumberException();
        }
    }
}




/*
 * @brief check invalid input size of board
 * @param width: width of board ( 5<width<30 )
 *        height: height of board ( 5<height<15 )
 */
void checkInvalid::checkInvalidSizeBoard(string width_str, string height_str)
{
    checkInvalidInteger(width_str);
    checkInvalidInteger(height_str);

    int width = stoi(width_str);
    int height = stoi(height_str);
    if (width > MAX_SIZE_BOARD_X || height >  MAX_SIZE_BOARD_Y
            || width < MIN_SIZE_BOARD_X || height < MIN_SIZE_BOARD_Y)
    {
        throw SizeBoardException();
    }
}


/*
 * @brief check input is 1 or 2
 * @param str: string input
 */
void checkInvalid::checkInvalidCommandMain(string str)
{
    checkInvalidInteger(str);
    int command = stoi(str);
    if (command != 1 && command !=2 && command !=3)
    {
        throw CommandException();
    }
}


/*
 * @brief check input is 1 or 2
 * @param str: string input
 */
void checkInvalid::checkInvalidCommandReplay(string str)
{
    checkInvalidInteger(str);
    int command = stoi(str);
    if (command != 1 && command !=2)
    {
        throw CommandException();
    }
}

/*
 * @brief check name input (0<len<20)
 * @param str: string input
 */
void checkInvalid::checkInvalidName(string str)
{
    if (str.length()>20||str.length()<=0)
    {
        throw NameException();
    }
}



