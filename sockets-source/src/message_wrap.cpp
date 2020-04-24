#include <message_wrap.hpp>
#include <iostream>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <string.h>//strtock c lib
#include <server.hpp>
#include <vector>
using namespace std;
unordered_set<string> cmd;
string send_command;
Sensor_data_t sensor_response;
Sensor_t request;
string resp;
char *get_time_stap (time_t raw)
{
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
const char * get_response()
{
    resp = get_time_stap(sensor_response.timestamp);
    if(request == Temperature)
    {
        resp+= "Temperature ";
        resp+= to_string(sensor_response.temperature)+"\n";
    }
    else if (request == Humidity)
    {
        resp+= "Humidity ";
        resp+= to_string(sensor_response.moistrue)+"\n";
    }
    else
    {
        resp+= "Temperature ";
        resp+= to_string(sensor_response.temperature);
        resp+= "Humidity ";
        resp+= to_string(sensor_response.temperature)+"\n";
    }
    return resp.c_str();
}
bool message_process(char* msg)
{
    char *token = strtok(msg, " ");
    bool valid_param = false;
    vector<string> params;
    if(cmd.find(token) != cmd.end())
    {
        cout << "SERVER: RECEIVED DATE REQUEST" << std::endl;
        valid_param =true;
        while (token != NULL) 
        { 
            printf("parameters: %s\n", token);
            params.emplace_back(token);
            token = strtok(NULL, " ");
        }  
    }
    auto first_parameter = cmd.find(params[0]);
    if(first_parameter != cmd.end()) // check a valid parameter
    {
        if(params.size() == 1)
        {
            if((*first_parameter).c_str() == TEMP)
            {
                request = Temperature;
            }
            else if ((*first_parameter).c_str() == HUMIDTY)
            {
                request = Humidity;
            }
            else if((*first_parameter).c_str() == BOTH)
            {
                request = Both;
            }
        }else
        {
            if((params[2]).c_str() == TEMP)
            {
                request = Temperature;
            }
            else if ((params[2]).c_str() == HUMIDTY)
            {
                request = Humidity;
            }
            else if((params[2]).c_str() == BOTH)
            {
                request = Both;
            }
        }
    }else
    {
        return 0;
    }

    get_sensor_data(sensor_response);
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
