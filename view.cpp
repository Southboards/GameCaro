#include "Headers/View/view.h"

View::View()
{

}

/*
 * @brief getter board
 * @return data board
 */
 Board View::getBoard()
 {
     return board;
 }



 /*
  * @brief screen for menu main
  */
 void View::screenMenuMain()
 {
     //SetConsoleTitle(L"Game Caro");
     system("cls");
     gotoXY(0,0);
     cout << "\t\tGame Caro" << endl;
     cout << "Enter '1' to Login." << endl;
     cout << "Enter '2' to Register." << endl;
     cout << "Enter '3' to End." << endl;
 }


 /*
  * @brief screen get command for menu main
  * @param return in this commnad (ref)
  */
void View::screenGetCommandMain(int& command)
{
    clearLine(4);
    clearLine(5);
    clearLine(6);

    gotoXY(0,4);
    cout << "Command: " ;
    fflush(stdin);
    string command_str;
    getline(cin>>ws, command_str);
    try
    {
        checkInvalid::checkInvalidCommandMain(command_str);
        command = stoi(command_str);
    }
    catch (NumberException& e)
    {
        gotoXY(0,5);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandStart(command);
    }
    catch (CommandException& e)
    {
        gotoXY(0,5);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandStart(command);
    }
    catch (...)
    {
        gotoXY(0,5);
        cout << "Input Invalid !" << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandStart(command);
    }
}


/*
 * @brief screen get account and pass
 * @param account (ref)
 * @param password (ref)
 */
void View::screenLogin(string& account, string& password)
{
    clearLine(1);
    clearLine(2);
    clearLine(3);
    clearLine(4);
    clearLine(5);
    clearLine(6);

    gotoXY(0,1);
    cout << "Account: " ;
    fflush(stdin);
    getline(cin>>ws, account);
    cout << "Password: " ;
    fflush(stdin);
    getline(cin>>ws, password);


}


/*
 * @brief screen login fail
 */
void View::screenLoginFail()
{
    gotoXY(0,3);
    cout << "Account No Existed or Wrong pass word!" << endl;
    cout << "Press enter to continue. " ;
    fflush(stdin);
    cin.ignore();
}

/*
 * @brief screen get new account and pass
 * @param account (ref)
 * @param password (ref)
 */
void View::screenRegister(string &account, string &password)
{
    clearLine(1);
    clearLine(2);
    clearLine(3);
    clearLine(4);
    clearLine(5);
    clearLine(6);

    gotoXY(0,1);
    cout << "New Account: " ;
    fflush(stdin);
    getline(cin>>ws, account);
    cout << "Password: " ;
    fflush(stdin);
    getline(cin>>ws, password);

    string linkPlayerFile = "D:/QT/GameCaro/Databases/" + account + ".ini";
    if (FileFunction::checkExistAccount(linkPlayerFile))
    {
        gotoXY(0,3);
        cout << "Account Existed !" << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenLogin(account, password);
    }

}

/*
 * @brief screen login done
 */
void View::screenRegisterDone()
{
    gotoXY(0,3);
    cout << "Register account completed !" << endl;
    cout << "Press enter to continue. " ;
    fflush(stdin);
    cin.ignore();
}

/*
 * @brief screen main
 */
void View::screenMenuStart()
{
    system("cls");
    gotoXY(0,0);
    cout << "\t\tGame Caro" << endl;
    cout << "Enter '1' to New Game." << endl;
    cout << "Enter '2' to Show Rank." << endl;
    cout << "Enter '3' to Log Out." << endl;

}


/*
 * @brief screen get command in screen start
 * @param return in this commnad (ref)
 */
void View::screenGetCommandStart(int& command)
{
    clearLine(4);
    clearLine(5);
    clearLine(6);

    gotoXY(0,4);
    cout << "Command: " ;
    fflush(stdin);
    string command_str;
    getline(cin>>ws, command_str);
    try
    {
        checkInvalid::checkInvalidCommandMain(command_str);
        command = stoi(command_str);
    }
    catch (NumberException& e)
    {
        gotoXY(0,5);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandStart(command);
    }
    catch (CommandException& e)
    {
        gotoXY(0,5);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandStart(command);
    }
    catch (...)
    {
        gotoXY(0,5);
        cout << "Input Invalid !" << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandStart(command);
    }
}


/*
 * @brief screen set up player
 * @param namePlayer1: name of player 1 (ref)
 *        namePlayer2: name of player 2 (ref)
 */
void  View::screenSetPlayer(string& namePlayer1, string& namePlayer2)
{
    clearLine(1);
    clearLine(2);
    clearLine(3);
    clearLine(4);
    clearLine(5);
    clearLine(6);
    gotoXY(0,1);
    cout << "Name player 1: ";
    fflush(stdin);
    getline(cin>>ws, namePlayer1);
    cout << "Name player 2: ";
    fflush(stdin);
    getline(cin>>ws, namePlayer2);

    try
    {
        checkInvalid::checkInvalidName(namePlayer1);
        checkInvalid::checkInvalidName(namePlayer2);
    }
    catch (NameException& e)
    {
        gotoXY(0,4);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenSetPlayer(namePlayer1, namePlayer2);
    }
    catch (...)
    {
        gotoXY(0,4);
        cout << "Input Invalid !" << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenSetPlayer(namePlayer1, namePlayer2);
    }
}


/*
 * @brief screen show infomation player
 * @param game: game's info
 */
void View::screenInfoGame(Game game)
{
    system("cls");
    gotoXY(0,0);
    cout << "\t\tGame Caro" << endl;

    cout << game.getPlayerGame(PLAYER_1).getName() ;
    cout << " (Elo " << FileFunction::getStringNumber(game.getPlayerGame(PLAYER_1).getEloPlayer()) << "): " ;
    cout << "Win: " << game.getPlayerGame(PLAYER_1).getNumWins() << "  ";
    cout << "Draw: " << game.getPlayerGame(PLAYER_1).getNumDraws() << "  ";
    cout << "Lose: " << game.getPlayerGame(PLAYER_1).getNumLoses() << endl;

    cout << game.getPlayerGame(PLAYER_2).getName() ;
    cout << " (Elo " << FileFunction::getStringNumber(game.getPlayerGame(PLAYER_2).getEloPlayer()) << "): " ;
    cout << "Win: " << game.getPlayerGame(PLAYER_2).getNumWins() << "  ";
    cout << "Draw: " << game.getPlayerGame(PLAYER_2).getNumDraws() << "  ";
    cout << "Lose: " << game.getPlayerGame(PLAYER_2).getNumLoses() << endl;

}


/*
 * @brief screen set up board
 */
void View::screenGetSizeBoard(int& width, int& height)
{
    clearLine(4);
    clearLine(5);
    clearLine(6);
    clearLine(7);
    gotoXY(0,4);
    cout << "Enter width of board: " ;
    string width_str ;
    fflush(stdin);
    getline(cin>>ws, width_str);

    cout << "Enter height of board: "   ;
    string height_str ;
    fflush(stdin);
    getline(cin>>ws, height_str);;



    try
    {
        checkInvalid::checkInvalidSizeBoard(width_str, height_str);
        width = stoi(width_str);
        height = stoi(height_str);
    }
    catch (NumberException& e)
    {
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetSizeBoard(width, height);

    }
    catch (SizeBoardException& e)
    {
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetSizeBoard(width, height);

    }
    catch (...)
    {
        cout << "Input Invalid !" << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetSizeBoard(width, height);

    }


}


/*
 * @brief screen show board
 */
void View::screenShowBoard()
{
    clearLine(3);
    clearLine(4);
    clearLine(5);
    clearLine(6);
    clearLine(7);

    setColor(3);
    drawBoard();
    setColor(15);
}


/*
 * @brief draw board game
 */
void View::drawBoard()
{
    gotoXY(0,9);

    for (int j=0;j<board.getWidth();j++)
    {
        cout << "----"  ;
    }
    cout << endl;

    for (int i=0;i<board.getHeight();i++)
    {
        cout << "|" ;
        for (int j=0;j<board.getWidth();j++)
        {
            cout << "   |"  ;
        }
        cout << endl;
        for (int j=0;j<board.getWidth();j++)
        {
            cout << "----"  ;
        }
        cout << endl;
    }
}



/*
 * @brief draw X or O
 * @param X: X if true, 0 if false
 *        pose: pose in board (coord Board)
 */
void View::drawMove(bool X, COORD pose)
{
    board.getBoard()[pose.Y][pose.X] = 1;

    pose = transCoordBoardToConsole(pose);
    gotoXY(pose.X, pose.Y);
    if (X)
    {
        setColor(4);
        cout << "X" << endl;
        setColor(15);
    }
    else
    {
        setColor(10);
        cout << "O" << endl;
        setColor(15);
    }

}




void View::setBoard(int width, int height)
{
    clearLine(5);
    clearLine(6);

    board = Board(width, height);

    /* resize console */
    if (width<10 || height <10)
    {
        setWindowSize(40, 30);
    }
        else
    {
        setWindowSize((width)*4+2, (height+4)*2+2);
    }

    screenShowBoard();
}

/*
 * @brief screen show turn
 * @param game: game in play
 *        turn: turn's player
 */
void View::screenTurn(Game game, bool turn)
{
    gotoXY(0,4);
    cout << "Turn: " ;
    if (turn)
    {
        cout << "(X) " ;
    }
    else
    {
        cout << "(O) " ;
    }
    cout << game.getPlayerGame(turn).getName() << "         " << endl;
}




/*
 * @brief screen show winner
 * @param game: game in play
 *        turn: turn's player
 */
void View::screenShowEndGame(Game game, bool turn)
{
    clearLine(4);
    gotoXY(0,4);
    cout << "\t\t" << game.getPlayerGame(turn).getName() << " WIN !!!         ";
}




/*
 * @brief screen show draw
 * @param game: game in play
 *        turn: turn's player
 */
void View::screenShowEndGame()
{
    clearLine(4);
    gotoXY(0,4);
    cout << "\t\tDRAW !!!";
}

/*
 * @brief screen get command in screen replay
 * @param return in this commnad (ref)
 */
void View::screenGetCommandReplay(int& command)
{
    clearLine(6);
    clearLine(7);
    gotoXY(0,5);
    cout << "Enter '1' to replay. Enter '2' to exit. " << endl;

    try
    {
        gotoXY(0,6);
        cout << "Command: " ;
        fflush(stdin);
        string command_str;
        getline(cin>>ws, command_str);
        checkInvalid::checkInvalidCommandReplay(command_str);
        command = stoi(command_str);
    }
    catch (NumberException& e)
    {
        gotoXY(0,6);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandReplay(command);
    }
    catch (CommandException& e)
    {
        gotoXY(0,6);
        cout << e.what() << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandReplay(command);
    }
    catch (...)
    {
        gotoXY(0,6);
        cout << "Input Invalid !" << endl;
        cout << "Press enter to continue. " ;
        fflush(stdin);
        cin.ignore();
        screenGetCommandReplay(command);
    }

}



/*
 * @brief set of screen console size
 * @param width: width of screen
 *        height: heght of screen
 */
void View::setWindowSize(SHORT width, SHORT height)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(console, 1, &WindowSize);

}


void View::GetMousePosWin(COORD& mouse)
{
    int x,y;
    INPUT_RECORD Inrec;
    DWORD eventRead;
    HANDLE hStdIn;
    DWORD dwMode;
    bool Captured=false;
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    /* kt console o che do nhan input hay chua */
    if( SetConsoleMode( hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)
    {
        GetConsoleMode(hStdIn, &dwMode);
        SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

        /* lay cac event ra de xu ly */
        do
        {
            PeekConsoleInput(hStdIn, &Inrec, 1, &eventRead);
            if( eventRead )
            {
                /* lay postion mouse */
                ReadConsoleInput(hStdIn, &Inrec, 1, &eventRead);
                x= Inrec.Event.MouseEvent.dwMousePosition.X ;
                y= Inrec.Event.MouseEvent.dwMousePosition.Y ;
                switch (Inrec.EventType )
                {

                case MOUSE_EVENT:
                    {
                        Captured = true;
                        mouse.X = x;
                        mouse.Y = y;
                        break;
                    }
                }
            }

        }while(!Captured);
    }
}

bool View::MouseEventProc(MOUSE_EVENT_RECORD mer, COORD& mouse)
{
    bool checkClick;
    switch(mer.dwEventFlags)
    {
        /* CLick */
        case 0:
            GetMousePosWin(mouse);
            checkClick = 1;
            break;
        case DOUBLE_CLICK:
            GetMousePosWin(mouse);
            checkClick = 1;
            break;
        default:
            checkClick = 0;
            break;
    }
    return checkClick;

}


COORD View::getPositionMouseClick()
{
    COORD mouse = {0,0};
    HANDLE hStdin;
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    bool checkClick = 0;



    // Get the standard input handle.

    hStdin = GetStdHandle(STD_INPUT_HANDLE);

//    DWORD test;
//    GetConsoleMode(hStdin, &test);
//    cout << test << endl;

    if (hStdin == INVALID_HANDLE_VALUE)
    {
        ExitProcess(0);
    }

    // console che do open
    fdwMode = ENABLE_EXTENDED_FLAGS;
    if (! SetConsoleMode(hStdin, fdwMode))
    {
        ExitProcess(0);
    }

    // console che do get input

    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (! SetConsoleMode(hStdin, fdwMode))
    {
        ExitProcess(0);
    }

    // quet event
    while (!checkClick)
    {
        // read event
        if (! ReadConsoleInput(hStdin,irInBuf,128,&cNumRead))
        {
            ExitProcess(0);
        }
        //xu ly tung event
        for (i = 0; i < cNumRead; i++)
        {
            switch(irInBuf[i].EventType){
            case MOUSE_EVENT: // event chuot
                checkClick = MouseEventProc(irInBuf[i].Event.MouseEvent, mouse);
                break;
            default:
                break;
            }
        }
    }
    try
    {
        COORD posOnBoard = transCoordConsoleToBoard(mouse);
        checkInvalid::checkInvalidClick(board, posOnBoard);
        checkInvalid::checkInvalidClick(mouse);
    }
    catch (ClickException& e)
    {
       gotoXY(0,5);
       cout << e.what() << endl;
       mouse = getPositionMouseClick();
    }
    clearLine(5);

    // back to default console
    SetConsoleMode(hStdin, 487);

    return mouse;
}


/*
 * @brief goto the poisiton of console
 * @param x: coord x
 * @param y: coord y
 */
void View::gotoXY(int x, int y)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD currentPosition;
    currentPosition.X = x;
    currentPosition.Y = y;
    SetConsoleCursorPosition(console, currentPosition);
}


/*
 * @brief clear rows
 * @param row: clear this row
 */
void View::clearLine(int row)
{
    gotoXY(0, row);
    cout << "                                                                                 " << endl;
}


/*
 * @brief set color
 * @param color
 */
void View::setColor(int color)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, color);
}


/*
 * @brief transform coord console to coord board
 * @return coord: coord Consolse
 */
COORD View::transCoordConsoleToBoard(COORD pos)
{
    COORD cell;

    cell.X = pos.X/4;
    cell.Y = pos.Y/2 - 5;

    return cell;
}

/*
 * @brief transform coord board to coord console
 * @return coord: coord board
 */
COORD View::transCoordBoardToConsole(COORD cell)
{
    COORD pos;
    pos.X = cell.X*4 + 2;
    pos.Y = (cell.Y+5)*2;
    return pos;
}


/*
 * @brief screen show player rank
 */
void View::screenRank(AccountList list)
{
    clearLine(1);
    clearLine(2);
    clearLine(3);
    clearLine(4);
    clearLine(5);
    clearLine(6);

    gotoXY(0,1);
    multimap<float, string, greater<float>> sortList;
    sortList = list.sortRank();

    cout << "\tRank Player" << endl;

    multimap<float, string, greater<float>>::iterator itr;
    int i = 1;
    for (itr = sortList.begin(); itr != sortList.end() ; itr++)
    {
        cout << "Top " << FileFunction::getStringNumber(i) << ": " ;
        cout << FileFunction::getStringName(itr->second);
        cout << "Elo: " << itr->first << endl;
        i++;
    }

    cout << "Press enter to continue. " ;
    fflush(stdin);
    cin.ignore();

}


void View::waitGame()
{
    clearLine(5);
    clearLine(6);
    gotoXY(0,5);
    cout << "Find game ... " << endl;
}





