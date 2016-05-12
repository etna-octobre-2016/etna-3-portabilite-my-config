#include "../header/header.h"

using namespace std;

Cpu::Cpu()
{

}

unsigned int Cpu::getCoresCount()
{
    #ifdef _WIN32
        using namespace System;
        
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        
        coresCount =  sysInfo.dwNumberOfProcessors;
     #elif __APPLE__
        size_t size = sizeof(coresCount);
        sysctlbyname("hw.activecpu", &coresCount, &size, NULL, 0);
     #else
        coresCount = 0;
     #endif
     
     return coresCount;   
}

uint64_t Cpu::getFreq()
{
    #ifdef _WIN32
        freq = 0;
     #elif __APPLE__
        size_t size = sizeof(freq);
        if(sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0)
        {
            perror("sysctl");
        }
     #else
        freq = 0;
     #endif
     
     return freq;
}

string Cpu::getCpuInfo()
{
    #ifdef _WIN32
        using namespace Microsoft::Win32;
        using namespace System;
        using namespace Runtime::InteropServices;
        RegistryKey^ rk = nullptr;
   
        rk = Registry::LocalMachine->OpenSubKey("hardware\\DESCRIPTION\\System\\CentralProcessor\\0", false);
        if (rk==nullptr)
        {
            Console::WriteLine("Registry key not found - aborting");
            cpuinfo = "noinformations";
        }
        else
        {
            String^ valueName = "ProcessorNameString";
            String^ def =(String^) rk->GetValue(valueName);   
            const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(def)).ToPointer();
            cpuinfo = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
        }
    #elif __APPLE__
        char buf[100];
        size_t buflen = 100;
        sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
        cpuinfo = buf;
    #else
        cpuinfo  = "";
    #endif
    return cpuinfo;
}
