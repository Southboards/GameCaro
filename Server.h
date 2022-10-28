#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <ws2tcpip.h>
#include "../Headers/ProtocolFunction.h"
#include <unordered_map>

#pragma comment (lib, "ws2_32.lib")

using namespace std;


#define MAX_BUFFER_SIZE 49152U



class Server;
typedef void(*MessageReceivedHandler)(Server* listener, int socketID, string msg);



/**********
 * API
**********/

class Server
{
private:
    string ipAddress;
    int port;
    MessageReceivedHandler msgReceived;



    unordered_map<SOCKET, string> waitingGame;
    bool turn = 0;
    int argWidth = 0;
    int argHeight = 0;

    bool replay = 1;



    /*
     * @brief clean up wsa
     */
    void cleanUp();

    /*
     * @brief create new socket listener
     * @return new socket
     */
    SOCKET createSocket();


    /*
     * @brief create new socket client
     * @return new socket client
     */
    SOCKET waitConnection(SOCKET listening);

    /*
     * @brief case controller to send command to 2 client
     */
    void controller(fd_set master, SOCKET listening, SOCKET sock, char* msg);


    /*
     * @brief case find game
     */
    void findGame(fd_set master, SOCKET listening, SOCKET sock, char* buf);


    /*
     * @brief case set up  board
     */
    void setupBoard(SOCKET sock, char* buf);

    void playerMove(SOCKET sock, char* buf);

    void replayGame(SOCKET sock, char* buf);

public:
    Server(string ipAddress, int port, MessageReceivedHandler handler);
    ~Server();

    /*
     * @brief main run
     */
    void run();

    /*
     * @brief init server
     * @return true: completed
     *         false: init fail
     */
    bool initServer();



    /*
     * @brief send data
     * @param clientSocket: client received
     *        msg: msg data
     */
    void sendMsg(int clientSocket, string msg);





};

#endif // SERVER_H
