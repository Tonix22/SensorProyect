#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;
float get_temperature_sensor()
{
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(-3, 3); // define the range
    srand((unsigned int)distr(eng));
    float decimal = (rand()) / static_cast <float> (RAND_MAX);
    float room_temp = 25.0 + distr(eng)+decimal;
    return room_temp;
}
float get_humidity_sensor()
{
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(-10, 10); // define the range
    srand((unsigned int)distr(eng));
    float decimal = (rand()) / static_cast <float> (RAND_MAX);
    float room_humidity = 50 + distr(eng)+decimal;
    return room_humidity;
}