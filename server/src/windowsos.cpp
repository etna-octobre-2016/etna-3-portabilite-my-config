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
	name = "unknown";
	OSVERSIONINFO osvi;
	SYSTEM_INFO si;
	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);
	DWORD dwType;
	GetProductInfo(osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType);

	if (dwType == 48)
		name = "Microsoft Windows 10 Professionnel";


    return name;
}

int Windowsos::getArchitecture()
{
	BOOL bIs64Bit = FALSE;
	typedef BOOL(WINAPI *LPFNISWOW64PROCESS) (HANDLE, PBOOL);
	LPFNISWOW64PROCESS pfnIsWow64Process = (LPFNISWOW64PROCESS)GetProcAddress(GetModuleHandle("kernel32"), "IsWow64Process");

	if (pfnIsWow64Process)
		pfnIsWow64Process(GetCurrentProcess(), &bIs64Bit);

	if (bIs64Bit)
		architecture = 64;
	else
		architecture = 32;

    return architecture;
}