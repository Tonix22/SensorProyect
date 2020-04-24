#ifndef MESSAGE_WRAP_HPP_INCLUDED
#define MESSAGE_WRAP_HPP_INCLUDED
#define SERVER        "server"
#define CLIENT        "client"
#define DATE          "DATE"
#define QUERY         "Sensor"
#define TEMP          "Temp"
#define HUMIDTY       "Hum"
#define BOTH          "Both"
#define TIMEQUERY     "Time"

char *get_time_stap ();
void init_commands();
bool message_process(char* msg);
bool MakeInputString(int argc, char const *argv[]);

#endif