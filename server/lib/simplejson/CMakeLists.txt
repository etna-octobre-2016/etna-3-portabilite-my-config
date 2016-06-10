cmake_minimum_required(VERSION 3.5.2)
project(simplejson)
add_library(
    ${PROJECT_NAME}
    SHARED
    JSON.h
    JSONValue.h
    JSON.cpp
    JSONValue.cpp
)