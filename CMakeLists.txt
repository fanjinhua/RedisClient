cmake_minimum_required(VERSION 3.6)
project(RedisClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp inc/network/tcp_client.h inc/network/tcp_client.cpp inc/err.h inc/RedisClient.h src/RedisClient.cpp)
add_executable(RedisClient ${SOURCE_FILES})