add_library(
    server
    server.cpp 
    server.hpp
)
target_link_libraries(server PRIVATE databaseSensorData sensor-driver sensor-comunication)
target_include_directories(server PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(sensor main.cpp)


target_link_libraries(sensor PRIVATE server databaseSensorData sensor-driver sensor-comunication)