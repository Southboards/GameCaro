#include "Headers/controller.h"

controller::controller()
{

}


void controller::Listener_MessageReceived(Server* listener, int client, string msg)
{
    listener->sendMsg(client, msg);
}


void controller::run()
{
    Server server(IP_SERVER, PORT_SERVER, Listener_MessageReceived);
    if (server.initServer())
    {
        server.run();
    }
}
