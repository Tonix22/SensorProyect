add_library(
    databaseSensorData
    src/Database.cpp
    src/Database.hpp
)
target_link_libraries(databaseSensorData /home/student/libs/lib/libsqlite3.a -ldl)

target_include_directories(databaseSensorData PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")