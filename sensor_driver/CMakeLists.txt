add_library(
    sensor-driver
    src/sensors.cpp
    src/sensors.hpp
)
target_include_directories(sensor-driver PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")