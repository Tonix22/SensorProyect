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

#define IPCSERVERCLIENT "ipc:///tmp/reqrep.ipc"
int server_socket (const char *url);
int client_socket (const char *url);
#endif