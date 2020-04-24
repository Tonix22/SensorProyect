#include <comunication.hpp>
#include <message_wrap.hpp>
#include <sensors.hpp>
#include <Database.hpp>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    if (strncmp (SERVER, argv[1], strlen (SERVER)) == 0)
    {
        init_data_base();
        init_commands();
        return server (IPCSERVERCLIENT);
    }
    else if (strncmp (CLIENT, argv[1], strlen (CLIENT)) == 0  && argc > 2)
    {
        //COMANDS FROM CLIENT TO SERVER
        //"Sensor Temp" --> returns last taken temperature
        //"Sensor Hum" --> returns last taken humidty
        //"Sensor Both"--> returns last boths
        //"Time <timestamp> <sensor type>" --> return sensor output in that time
        if( MakeInputString(argc,argv) )
        {
            return client (IPCSERVERCLIENT);
        }
        else
        {
            cout << "invalid message" << endl;
        }
    }
    else
    {
        cout << "invalid message" << endl;
        return 1;
    }
    
    return 0;
}
