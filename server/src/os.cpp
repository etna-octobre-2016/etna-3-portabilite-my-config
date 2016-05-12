#include "../header/header.h"

using namespace std;

Os::Os()
{

}

string Os::getName()
{
    #ifdef _WIN32
        using namespace Microsoft::Win32;
        using namespace System;
        using namespace Runtime::InteropServices;
        RegistryKey^ rk = nullptr;
        
        rk = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", false);
        if (rk==nullptr)
        {
            Console::WriteLine("Registry key not found - aborting");
            name = "no informations";
        }
        else
        {
            String^ valueName = "ProductName";
            String^ def =(String^) rk->GetValue(valueName);   
            const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(def)).ToPointer();
            name = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
        }
    #elif __APPLE__
        struct utsname sysinfo;
        uname(&sysinfo);
        name = sysinfo.release;
        if (name.find("15") != std::string::npos)
            name = "El Capitan";
        else if (name.find("14") != std::string::npos)
            name = "Yosemite";
        else if (name.find("13") != std::string::npos)
            name = "Mavericks";
        else
            name = "unknow";
    #else
        name  = "";
    #endif
    
    return name;
}

int Os::getArchitecture()
{
    #ifdef _WIN32
        using namespace Microsoft::Win32;
        using namespace System;
        using namespace Runtime::InteropServices;
        RegistryKey^ rk = nullptr;
        
        rk = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", false);
        if (rk==nullptr)
        {
            Console::WriteLine("Registry key not found - aborting");
            architecture = -1;
        }
        else
        {
            String^ valueName = "BuildLabEx";
            String^ def =(String^) rk->GetValue(valueName);   
            const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(def)).ToPointer();
            string name = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
            if (name.find("amd64") != std::string::npos)
            {
                architecture = 64;
            }
            else
            {
                architecture = 32;
            }
        }
    #elif __APPLE__
        struct utsname sysinfo;
        uname(&sysinfo);
        string arch = sysinfo.machine;
        if (arch.find("64") != std::string::npos)
            architecture = 64;
        else
            architecture = 32;
    #else
        architecture  = 0;
    #endif   
    return architecture;
}