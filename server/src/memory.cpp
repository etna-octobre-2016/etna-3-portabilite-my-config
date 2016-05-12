#include "../header/header.h"

using namespace std;

Memory::Memory()
{
    #ifdef _WIN32
        statex.dwLength = sizeof(statex);
        GlobalMemoryStatusEx(&statex);
    #endif
}

uint64_t Memory::getTotalRam()
{
    #ifdef _WIN32   
        totalram = statex.ullTotalPhys/1024;
    #elif __APPLE__
        size_t size = sizeof(totalram);
        sysctlbyname("hw.memsize", &totalram, &size, NULL, 0);
        totalram = totalram / 1024;
    #else
        totalram = 0;
    #endif
    
    return totalram;
}

unsigned int Memory::getFreeRam()
{
    #ifdef _WIN32
        freeram = statex.ullAvailPhys/1024;
    #elif __APPLE__
        vm_size_t page_size;
        mach_port_t mach_port;
        mach_msg_type_number_t count;
        vm_statistics64_data_t vm_stats;

        mach_port = mach_host_self();
        count = sizeof(vm_stats) / sizeof(natural_t);
        if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
            KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
        {
            freeram = (int64_t)vm_stats.free_count * (int64_t)page_size;
        }
        freeram = freeram / 1024;
    #else
        freeram = 0;
    #endif
    return freeram;
}

unsigned int Memory::getPourcentRam()
{
    #ifdef _WIN32
        pourcentusedram = statex.dwMemoryLoad;
    #elif __APPLE__
        vm_size_t page_size;
        mach_port_t mach_port;
        mach_msg_type_number_t count;
        vm_statistics64_data_t vm_stats;

        mach_port = mach_host_self();
        count = sizeof(vm_stats) / sizeof(natural_t);
        if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
            KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
        {
        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
        pourcentusedram = (used_memory / 1024) * 100 / getTotalRam();
        }
    #else
        pourcentusedram = 0;
    #endif
    return pourcentusedram;
}