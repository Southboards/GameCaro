#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <string>
#include <ws2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;


/**********
 * DEFINE
**********/
#define MAX_BUFFER_SIZE 49152U

#define IP_SERVER        "192.168.56.1"
#define PORT_SERVER      9090


/**********
 * API
**********/



class Client
{
private:
    string ipAddress;
    int port;
    SOCKET sock;
public:
    Client();

    /*
     * @brief main run
     */
    void run();

    bool initClient();


    /*
     * @brief create new socket listener
     * @return new socket
     */
    SOCKET createSocket();

    /*
     * @brief clean up wsa
     */
    void cleanUp();


    int sendMsg(string msg);

    int listenReponse(string& reponse);

    void closeSocket();


};

#endif // CLIENT_H
