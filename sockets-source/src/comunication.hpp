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

#define SERVER "server"
#define CLIENT "client"
#define DATE "DATE"
#define IPCINSTANCE "ipc:///tmp/reqrep.ipc"
int server (const char *url);
int client (const char *url);
#endif