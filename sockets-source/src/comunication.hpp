#ifndef COMUNICATION_HPP_INCLUDED
#define COMUNICATION_HPP_INCLUDED
#include <iostream>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>

#define SERVER        "server"
#define CLIENT        "client"
#define DATE          "DATE"
#define QUERY         "Sensor"
#define TEMP          "Temp"
#define HUMIDTY       "Hum"
#define BOTH          "Both"
#define TIMEQUERY     "Time"
typedef enum
{
    Temperature,
    Humidity,
    Both,
}Sensor_t;


#define IPCINSTANCE "ipc:///tmp/reqrep.ipc"
void init_commands();
int server (const char *url);
int client (const char *url,int argc, char const *argv[]);
#endif