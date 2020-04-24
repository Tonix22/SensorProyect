add_executable(sensor main.cpp)
target_link_libraries(sensor PRIVATE databaseSensorData sensor-driver sensor-comunication )