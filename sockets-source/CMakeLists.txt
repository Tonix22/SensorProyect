add_library(
    sensor-comunication
    src/comunication.cpp
    src/comunication.hpp
)
find_package(nanomsg CONFIG REQUIRED)
target_link_libraries(sensor-comunication nanomsg)
target_include_directories(sensor-comunication PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")