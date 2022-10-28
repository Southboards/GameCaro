#include "Headers/Controller/client.h"

Client::Client()
{
    this->ipAddress = IP_SERVER;
    this->port = PORT_SERVER;
    initClient();
}


/*
 * @brief main run
 */
void Client::run()
{

    string msg;
    sock = createSocket();

    if (sock == INVALID_SOCKET)
    {
        return;
    }
}


int Client::listenReponse(string& reponse)
{
    if (sock == INVALID_SOCKET)
    {
        return 0;
    }

    char buf[MAX_BUFFER_SIZE];
    ZeroMemory(buf, MAX_BUFFER_SIZE);
    int bytesReceived = recv(sock, buf, MAX_BUFFER_SIZE, 0);
    if (bytesReceived > 0)
    {
        reponse = string(buf, 0, bytesReceived) ;
        return 1;
    }
    reponse = "";
    return 0;
}

void Client::closeSocket()
{
    closesocket(sock);
}


/*
 * @brief init server
 * @return true: completed
 *         false: init fail
 */
bool Client::initClient()
{
    /* Init winsock */
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsCheck = WSAStartup(ver, &wsData);
    if(wsCheck != 0)
    {
        return 0;
    }
    return 1;
}


/*
 * @brief create new socket listener
 * @return new socket
 */
SOCKET Client::createSocket()
{
    /* create socket */
    SOCKET newSock = socket(AF_INET, SOCK_STREAM, 0);
    if (newSock != INVALID_SOCKET)
    {
        /* set up socket to an ip port */
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        int connectCheck = connect(newSock,(sockaddr*)&hint, sizeof(hint));
        if (connectCheck == SOCKET_ERROR)
        {
            closesocket(newSock);
            return -1;
        }

        return newSock;
    }
    return -1;
}


/*
 * @brief send data
 * @param clientSocket: client received
 *        msg: msg data
 */
int Client::sendMsg(string msg)
{
    return send(sock, msg.c_str(), msg.size()+1, 0);
}

void Client::cleanUp()
{
    WSACleanup();
}
