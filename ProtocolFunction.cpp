#include "Headers/ProtocolFunction.h"

ProtocolFunction::ProtocolFunction()
{

}



string ProtocolFunction::msgFindGame(string account)
{
    string msg;
    msg += FIND_GAME_TYPE;
    msg += account;
    return msg;
}

string ProtocolFunction::reponseFindGame(string account, char X)
{
    string msg;
    msg += FIND_GAME_DONE_TYPE;
    msg += X;
    msg += account;
    return msg;
}

string ProtocolFunction::msgSizeBoard(uint8_t width, uint8_t height)
{
    string msg;
    msg += SIZE_BOARD_TYPE;
    msg += width;
    msg += height;
    return msg;
}

string ProtocolFunction::msgMove(uint8_t x, uint8_t y)
{
    string msg;
    msg += POS_MOVE_TYPE;
    msg += x;
    msg += y;
    return msg;
}


string ProtocolFunction::msgReplay(uint8_t replay)
{
    string msg;
    msg += REPLAY_TYPE;
    msg += replay;
    return msg;
}
