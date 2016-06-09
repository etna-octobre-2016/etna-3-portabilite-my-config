cmake_minimum_required(VERSION 3.5.2)
project(myconfigserver)

#################################################
# OPTIONS
#################################################

set(RESTBED_INCLUDE_DIR "" CACHE PATH "Restbed library include directory")
set(RESTBED_LIBRARY_DIR "" CACHE PATH "Restbed library binary directory")

#################################################
# Libraries
#################################################

find_library(RESTBED_LIB restbed PATHS ${RESTBED_LIBRARY_DIR})
include_directories(SYSTEM ${RESTBED_INCLUDE_DIR})

#################################################
# Compiling
#################################################

if(WIN32)

  set(CMAKE_CXX_FLAGS "/clr")
  set(CMAKE_CXX_FLAGS_DEBUG "")
  add_executable(
    ${PROJECT_NAME}

    header/cpu.h
    header/cpuwin.hpp
    header/hdd.h
    header/header.h
    header/memory.h
    header/memorywin.hpp
    header/os.h
    header/windowsos.hpp

    src/cpuwin.cpp
    src/hdd.cpp
    src/main.cpp
    src/memorywin.cpp
    src/windowsos.cpp
  )

elseif(APPLE)

  set(CMAKE_CXX_FLAGS "-std=c++11")
  add_executable(
    ${PROJECT_NAME}

    header/cpu.h
    header/cpumac.hpp
    header/hdd.h
    header/header.h
    header/macos.hpp
    header/memory.h
    header/memorymac.hpp
    header/os.h

    src/cpumac.cpp
    src/hdd.cpp
    src/macos.cpp
    src/main.cpp
    src/memorymac.cpp
  )

else(UNIX)

  set(CMAKE_CXX_FLAGS "-std=c++11")
  add_executable(
    ${PROJECT_NAME}

    header/cpu.h
    header/cpulinux.hpp
    header/hdd.h
    header/header.h
    header/memory.h
    header/memorylinux.hpp
    header/os.h
    header/linuxos.hpp

    src/cpulinux.cpp
    src/hdd.cpp
    src/linuxos.cpp
    src/main.cpp
    src/memorylinux.cpp
  )

endif()

#################################################
# LINKING
#################################################

target_link_libraries(${PROJECT_NAME} ${RESTBED_LIB})
