add_library(
    sensor-comunication
    src/comunication.cpp
    src/comunication.hpp
    src/message_wrap.cpp
    src/message_wrap.hpp
)
find_package(nanomsg REQUIRED CONFIG)
target_link_libraries(sensor-comunication nanomsg)
target_include_directories(sensor-comunication PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")


