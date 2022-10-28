#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "../Headers/Server.h"

using namespace std;


/**********
 * DEFINE
**********/
#define IP_SERVER        "192.168.56.1"
#define PORT_SERVER      9090




/**********
 * API
**********/


class controller
{
private:
    static void Listener_MessageReceived(Server* listener, int client, string msg);
public:
    controller();

    void run();
};

#endif // CONTROLLER_H
