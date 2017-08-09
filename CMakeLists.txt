cmake_minimum_required(VERSION 3.8)
project(challenge_hashing)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c hash_helper.c hash_helper.h person.h status.h person.c)
add_executable(challenge_hashing ${SOURCE_FILES})