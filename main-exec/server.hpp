#ifndef SERVER_HPP
#define SERVER_HPP

#include <ctime>

typedef struct server
{
    time_t timestamp;
    float temperature;
    float moistrue;
}Sensor_data_t;

void server_task();
void get_sensor_data(Sensor_data_t& sample);
#endif