#include "../header/header.h"

using namespace std;

using namespace Microsoft::Win32;
using namespace System;
using namespace Runtime::InteropServices;

Windowsos::Windowsos()
{
    
}

string Windowsos::getName()
{
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
    
    return name;
}

int Windowsos::getArchitecture()
{
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
		String^ def = (String^)rk->GetValue(valueName);
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
    return architecture;
}