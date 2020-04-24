#include <message_wrap.hpp>
#include <iostream>
#include <unordered_set>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <string.h>//strtock c lib
using namespace std;
unordered_set<string> cmd;
string send_command;


char *get_time_stap ()
{
  time_t raw = time (&raw);
  struct tm *info = localtime (&raw);
  char *text = asctime (info);
  text[strlen(text)-1] = '\0'; // remove '\n'
  return text;
}


void init_commands()
{
    cmd.insert(DATE);
    cmd.insert(QUERY);
    cmd.insert(TEMP);
    cmd.insert(HUMIDTY);
    cmd.insert(BOTH);
    cmd.insert(TIMEQUERY); // GO TO SEARCH TO SQL DATABASE
}

bool message_process(char* msg)
{
    char *token = strtok(msg, " ");
    bool valid_param = false;
    if(cmd.find(token) != cmd.end())
    {
        cout << "SERVER: RECEIVED DATE REQUEST" << std::endl;
        valid_param =true;
        while (token != NULL) 
        { 
            printf("parameters: %s\n", token); 
            token = strtok(NULL, " "); 
        }  
    }

    return valid_param;
}

bool MakeInputString(int argc, char const *argv[])
{
    bool valid_input = true;
    if(argc == 4 )
    {
        send_command= argv[2];
        send_command+= " ";
        send_command+=argv[3];
    }
    else if (argc == 5)
    {
        send_command=  argv[2];
        send_command+=  " ";
        send_command+= argv[3];
        send_command+=  " ";
        send_command+= argv[4];
    }
    else 
    {
      std::cout << argc << std::endl;
      valid_input = false;
    }
    return valid_input;
}
