#ifndef Database_HPP
#define Database_HPP
#include <ctime>
void init_data_base();
void push_data_temp(time_t time, float value);
void push_data_hum(time_t time, float value);
#endif