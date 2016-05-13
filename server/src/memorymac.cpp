#include "../header/header.h"

using namespace std;

Memorymac::Memorymac()
{
}

uint64_t Memorymac::getTotalRam()
{
    size_t size = sizeof(totalram);
    sysctlbyname("hw.memsize", &totalram, &size, NULL, 0);
    totalram = totalram / 1024;

    return totalram;
}

unsigned int Memorymac::getFreeRam()
{
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

    return freeram;
}

unsigned int Memorymac::getPourcentRam()
{
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

    return pourcentusedram;
}