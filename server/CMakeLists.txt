cmake_minimum_required(VERSION 3.5.2)
project(myconfigserver)

if(WIN32)

  set(CMAKE_CXX_FLAGS "/clr")
  set(CMAKE_CXX_FLAGS_DEBUG "")
  add_executable(
    ${PROJECT_NAME}

    header/client.h
    header/cpu.h
    header/cpuwin.hpp
    header/hdd.h
    header/header.h
    header/memorywin.hpp
    header/os.h
    header/socket.h
    header/windowsos.hpp

    src/client.cpp
    src/cpuwin.cpp
    src/hdd.cpp
    src/main.cpp
    src/memorywin.cpp
    src/socket.cpp
    src/windowsos.cpp
  )

elseif(APPLE)

  add_executable(
    ${PROJECT_NAME}

    header/client.h
    header/cpu.h
    header/cpumac.hpp
    header/hdd.h
    header/header.h
    header/macos.hpp
    header/memorymac.hpp
    header/os.h
    header/socket.h

    src/client.cpp
    src/cpumac.cpp
    src/hdd.cpp
    src/macos.cpp
    src/main.cpp
    src/memorymac.cpp
    src/socket.cpp
  )

else(UNIX)

  add_executable(
    ${PROJECT_NAME}

    header/client.h
    header/cpu.h
    header/cpulinux.hpp
    header/hdd.h
    header/header.h
    header/memorylinux.hpp
    header/os.h
    header/socket.h
    header/linuxos.hpp

    src/client.cpp
    src/cpulinux.cpp
    src/hdd.cpp
    src/linuxos.cpp
    src/main.cpp
    src/memorylinux.cpp
    src/socket.cpp
  )

endif()
