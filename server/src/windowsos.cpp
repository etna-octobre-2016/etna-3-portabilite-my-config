#include "../header/header.h"
#include <iostream>
#include <VersionHelpers.h>
using namespace std;

//using namespace Microsoft::Win32;
//using namespace System;
//using namespace Runtime::InteropServices;
//using namespace System::Management::Automation;

Windowsos::Windowsos()
{
    
}

string Windowsos::getName()
{
    /*RegistryKey^ rk = nullptr;
        
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
    }*/

		 //	ostringstream os;
			////os << "-ExecutionPolicy ByPass -NoProfile -NonInteractive -WindowStyle Hidden -File \"" << CT2A(theApp.GetApplicationFolder()) << "Prep-OptionsFile.ps1" << "\" \"" << CT2A(fileName) << "\" \"" << CT2A(ext) << "\"";
			//os << "Get - WmiObject Win32_OperatingSystem | Select - Object Caption, Version, ServicePackMajorVersion, OSArchitecture, CSName, WindowsDirectory, NumberOfUsers, BootDevice";
			//string op = "open";
			//string ps = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\PowerShell.exe";
	 	//    string param = os.str();
			//DWORD res = (int)ShellExecuteA(NULL, op.c_str(), ps.c_str(), param.c_str(), NULL, SW_HIDE);
	//system("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
	//system("start powershell.exe get-process");
	//system("cls");
	//char buffer[128];
	//string result = "";
	//FILE* pipe = _popen("start powershell.exe get - process", "r");
	//while (!feof(pipe)) {
	//	if (fgets(buffer, 128, pipe) != NULL)
	//		result += buffer;
	//}
	//_pclose(pipe);
	//cout << result << endl;
	OSVERSIONINFO osvi;
	SYSTEM_INFO si;
	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);
	DWORD dwType;
	GetProductInfo(osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType);
	cout << osvi.dwMajorVersion << endl;
	cout << osvi.dwMinorVersion << endl;

	cout << "dwtype : " << dwType << endl;
	cout << "variable : " << PRODUCT_ENTERPRISE << endl;


	LPTSTR pszOS;
	if (dwType == PRODUCT_ENTERPRISE_EVALUATION)
		cout << "Microsoft Windows 10 Professionnel" << endl;

		name = "rien";

    return name;
}

int Windowsos::getArchitecture()
{
    /*RegistryKey^ rk = nullptr;
        
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
	}*/

	architecture = 64;
    return architecture;
}