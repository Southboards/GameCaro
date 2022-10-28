#ifndef PROTOCOLFUNCTION_H
#define PROTOCOLFUNCTION_H


#include <iostream>
#include <string>

using namespace std;


/**********
 * DEFINE
**********/



/*************
 * PROTOTYPES
*************/

#define FIND_GAME_TYPE           0x01U
#define FIND_GAME_DONE_TYPE      0x02U
#define SIZE_BOARD_TYPE          0x03U
#define POS_MOVE_TYPE            0x04U
#define REPLAY_TYPE              0x05U

#define BOOL_FLASE          0x00U
#define BOOL_TRUE           0x01U


class ProtocolFunction
{
public:
    ProtocolFunction();


    static string msgFindGame(string account);

    static string reponseFindGame(string account, char X);

    static string msgSizeBoard(uint8_t width, uint8_t height);

    static string msgMove(uint8_t x, uint8_t y);

    static string msgReplay(uint8_t replay);
};

#endif // PROTOCOLFUNCTION_H
