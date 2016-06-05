#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
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
	#include "cpumac.hpp"
	#include "macos.hpp"
	#include "memorymac.hpp"
#else
	#include "cpulinux.hpp"
	#include "linuxos.hpp"
	#include "memorylinux.hpp"
#endif

#ifdef __unix__
	#include <sys/utsname.h>
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <sys/param.h>
    #include <sys/mount.h>
	#include <unistd.h>
#endif

#endif