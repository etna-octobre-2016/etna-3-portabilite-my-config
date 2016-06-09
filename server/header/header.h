#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <restbed>
#include "cpu.h"
#include "hdd.h"
#include "memory.h"
#include "os.h"
#if defined(_WIN32)
  #include <windows.h>
  #include "cpuwin.hpp"
  #include "memorywin.hpp"
  #include "windowsos.hpp"
#elif defined(__APPLE__)
  #include <sys/mount.h>
  #include <sys/param.h>
  #include <sys/sysctl.h>
  #include <sys/types.h>
  #include <sys/utsname.h>
  #include <unistd.h>
  #include "cpumac.hpp"
  #include "macos.hpp"
  #include "memorymac.hpp"
#else
  #include <sys/mount.h>
  #include <sys/param.h>
  #include <sys/sysctl.h>
  #include <sys/types.h>
  #include <sys/utsname.h>
  #include <unistd.h>
  #include "cpulinux.hpp"
  #include "linuxos.hpp"
  #include "memorylinux.hpp"
#endif
#endif
