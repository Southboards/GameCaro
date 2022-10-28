#include "Headers/Server.h"

Server::Server(string ipAddress, int port, MessageReceivedHandler handler)
{
    this->ipAddress = ipAddress;
    this->port = port;
    this->msgReceived = handler;

}

Server::~Server()
{
    cleanUp();
}




/*
 * @brief main run
 */
void Server::run()
{
    char buf[MAX_BUFFER_SIZE];
    SOCKET listening = createSocket();
    if (listening == INVALID_SOCKET)
    {
        return;
    }

    fd_set master;
    FD_ZERO(&master);
    FD_SET(listening, &master);
    cout << "Server run"  << endl;


    while (true)
    {
        fd_set copy = master;

        int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

        for (int i=0;i<socketCount;i++)
        {
            SOCKET sock = copy.fd_array[i];
            if (sock == listening)
            {
                // accept new connection
                SOCKET client = accept(listening, nullptr, nullptr);

                // add new connect to list client
                FD_SET(client, &master);

                // check
                cout << "Account active: " << master.fd_count-1 << endl;

            }

            else
            {
                int bytesReceived = 0;
                ZeroMemory(buf, MAX_BUFFER_SIZE);
                bytesReceived = recv(sock, buf, MAX_BUFFER_SIZE, 0);

                if (bytesReceived <= 0)
                {
                    closesocket(sock);
                    FD_CLR(sock, &master);
                    cout << "Account active: " << master.fd_count-1 << endl;
                }
                else
                {
                    controller(master, listening, sock, buf);
                }
            }
        }
    }
}


/*
 * @brief case controller to send command to 2 client
 */
void Server::controller(fd_set master, SOCKET listening, SOCKET sock, char* buf)
{
    if (buf[0] == 0x01)
    {
        cout << sock << " find game " << endl;
        findGame(master, listening,sock, buf);
    }

    if (buf[0] == 0x03)
    {
        cout << sock << " set up board " << endl;
        setupBoard(sock, buf);
    }

    if (buf[0] == 0x04)
    {
        cout << sock << " move " << endl;
        playerMove(sock, buf);
    }

    if (buf[0] == 0x05)
    {
        cout << sock << " replay " << endl;
        replayGame(sock, buf);
    }

}


/*
 * @brief case find game
 */
void Server::findGame(fd_set master, SOCKET listening, SOCKET sock, char* buf)
{
    string nameSock = string(buf);
    nameSock.replace(0, 1, "");
    pair<SOCKET, string> p(sock, nameSock);
    waitingGame.insert(p);
    for (int i=0;i<master.fd_count;i++)
    {
        SOCKET outSock = master.fd_array[i];
        if (outSock != listening && outSock == sock)
        {
            sendMsg(outSock, string(buf));
        }
    }

    if (waitingGame.size()>=2)
    {
        auto itr = waitingGame.begin();

        sendMsg(itr->first, ProtocolFunction::reponseFindGame((itr++)->second, 0x01));
        sendMsg((itr)->first, ProtocolFunction::reponseFindGame((itr--)->second, 0x02));
    }
}


/*
 * @brief case set up  board
 */
void Server::setupBoard(SOCKET sock, char* buf)
{
    if (argWidth==0 && argHeight==0 && turn==0)
    {
        turn = 1;
        argWidth = buf[1];
        argHeight = buf[2];
    }
    else if (argWidth!=0 && argHeight!=0 && turn!=0)
    {
        turn = 0;
        argWidth = (buf[1]+argWidth)/2;
        argHeight = (buf[2]+argHeight)/2;
        if (waitingGame.size()==2)
        {
            auto itr = waitingGame.begin();

            sendMsg(itr->first, ProtocolFunction::msgSizeBoard(argWidth, argHeight));
            itr++;
            sendMsg((itr)->first, ProtocolFunction::msgSizeBoard(argWidth, argHeight));
            argWidth = 0;
            argHeight = 0;
        }
    }


}

void Server::playerMove(SOCKET sock, char* buf)
{
    uint8_t move_x = buf[1];
    uint8_t move_y = buf[2];

    auto itr = waitingGame.begin();

    if (sock == itr->first)
    {
        itr++;
        sendMsg(itr->first, ProtocolFunction::msgMove(move_x, move_y));
    }
    else
    {
        sendMsg(itr->first, ProtocolFunction::msgMove(move_x, move_y));
    }
}

void Server::replayGame(SOCKET sock, char* buf)
{
    if (buf[1]==0x01)
    {
        replay = replay && 1;
    }
    else
    {
        replay = 0;
    }

    auto itr = waitingGame.begin();
    auto itr2 = itr++;

    if ( turn == 0 && (sock == (itr)->first || sock == (itr2)->first))
    {
        turn = 1;
        return;
    }

    if (turn == 1 && (sock == (itr)->first || sock == (itr2)->first))
    {
        turn = 0;

        if (replay == 1)
        {
            sendMsg(itr->first, ProtocolFunction::msgReplay(0x01));
            sendMsg(itr2->first, ProtocolFunction::msgReplay(0x01));
        }
        else
        {
           sendMsg(itr->first, ProtocolFunction::msgReplay(0x00));
           sendMsg(itr2->first, ProtocolFunction::msgReplay(0x00));
           waitingGame.clear();

        }
        replay = 0;

    }
}


/*
 * @brief send data
 * @param clientSocket: client received
 *        msg: msg data
 */
void Server::sendMsg(int clientSocket, string msg)
{
    send(clientSocket, msg.c_str(), msg.size()+1, 0);
}



/*
 * @brief init server
 * @return true: completed
 *         false: init fail
 */
bool Server::initServer()
{
    /* Init winsock */
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsCheck = WSAStartup(ver, &wsData);
    if(wsCheck != 0)
    {
        //cout << "Init fail !" << endl;
        return 0;
    }
    return 1;
}


/*
 * @brief clean up wsa
 */
void Server::cleanUp()
{
    WSACleanup();
}



/*
 * @brief create new socket listener
 * @return new socket
 */
SOCKET Server::createSocket()
{
    /* create socket */
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening != INVALID_SOCKET)
    {
        /* set up socket to an ip port */
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        int bindCheck = bind(listening, (sockaddr*)&hint, sizeof(hint));
        if (bindCheck != SOCKET_ERROR)
        {
            int listenCheck = listen(listening, SOMAXCONN);
            if (listenCheck == SOCKET_ERROR)
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
        return listening;
    }
    return -1;

}



/*
 * @brief create new socket client
 * @return new socket client
 */
SOCKET Server::waitConnection(SOCKET listening)
{
    SOCKET clientSocket = accept(listening, NULL, NULL);
    return clientSocket;
}
