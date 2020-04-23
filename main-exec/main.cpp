#include <comunication.hpp>
using namespace std;
int main(int argc, char const *argv[])
{

    if (strncmp (SERVER, argv[1], strlen (SERVER)) == 0)
    {
        init_commands();
        return server (IPCINSTANCE);
    }
    else if (strncmp (CLIENT, argv[1], strlen (CLIENT)) == 0  && argc > 2)
    {
        //COMANDS TO SERVER
        //"Sensor Temp" --> returns last taken temperature
        //"Sensor Hum" --> returns last taken humidty
        //"Sensor Both"--> returns last boths
        //"Time <timestamp> <sensor type>" --> return sensor output in that time
        return client (IPCINSTANCE, argc, argv);
    }
    else
    {
        cout << "invalid " << endl;
        return 1;
    }
    return 0;
}
