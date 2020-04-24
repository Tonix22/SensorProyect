
#include <unistd.h>
#include <sensors.hpp>
#include <server.hpp>
#include <Database.hpp>
#include <atomic>
Sensor_data_t sensing_data;

void take_sensors_sample(void)
{
    sensing_data.timestamp   = time(&(sensing_data.timestamp));
    sensing_data.temperature = get_temperature_sensor();
    sensing_data.moistrue    = get_humidity_sensor();
}
void get_sensor_data(Sensor_data_t& sample)
{
    sample.timestamp   = sensing_data.timestamp;
    sample.temperature = sensing_data.temperature;
    sample.moistrue    = sensing_data.moistrue;
}

void push_to_data_base()
{
    push_data_temp(sensing_data.timestamp, sensing_data.temperature);
    push_data_hum( sensing_data.timestamp, sensing_data.moistrue   );
}
void server_task()
{
    while(1)
    {
        sleep(5);
        take_sensors_sample();
        // sendo to data base
        //push_to_data_base();
        // send to socket buffer
        
    }
    
}