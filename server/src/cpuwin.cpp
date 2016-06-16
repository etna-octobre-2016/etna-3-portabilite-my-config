#include "../header/header.h"

using namespace std;
//using namespace Microsoft::Win32;
//using namespace System;
//using namespace Runtime::InteropServices;

Cpuwin::Cpuwin()
{

}

unsigned int Cpuwin::getCoresCount()
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    coresCount =  sysInfo.dwNumberOfProcessors;
     
    return coresCount;   
}

uint64_t Cpuwin::getFreq()
{
    freq = 0;
    return freq;
}

string Cpuwin::getCpuInfo()
{
   /* RegistryKey^ rk = nullptr;

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
    }*/
	cpuinfo = "test";

    return cpuinfo;
}
