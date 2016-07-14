#include "../header/header.h"

using namespace std;

Winhdd::Winhdd()
{

}

uint64_t Winhdd::getTotalCapacity()
{
	totalcapacity = 0;
	int dr_type = 99;
	char dr_avail[256];
	char *temp = dr_avail;
	GetLogicalDriveStrings(256, dr_avail);
	__int64 ttlspc, frspc;
	while (*temp != NULL)
	{
		GetDiskFreeSpaceEx(temp, 0, (PULARGE_INTEGER)&ttlspc, (PULARGE_INTEGER)&frspc);
		totalcapacity += ttlspc;
		temp += lstrlen(temp) + 1;
	}
	totalcapacity = totalcapacity / 1024 / 1024;

	return totalcapacity;
}

uint64_t Winhdd::getUsedCapacity()
{
	uint64_t freespace;
	freespace = 0;
	usedCapacity = 0;
	int dr_type = 99;
	char dr_avail[256];
	char *temp = dr_avail;
	GetLogicalDriveStrings(256, dr_avail);
	__int64 ttlspc, frspc;
	while (*temp != NULL)
	{
		GetDiskFreeSpaceEx(temp, 0, (PULARGE_INTEGER)&ttlspc, (PULARGE_INTEGER)&frspc);
		freespace += frspc;
		temp += lstrlen(temp) + 1;
	}
	freespace = freespace / 1024 / 1024;

	usedCapacity = getTotalCapacity() - freespace;

	return usedCapacity;
}

vector<string> Winhdd::getListHardDrive()
{
	int dr_type = 99;
	char dr_avail[256];
	char *temp = dr_avail;

	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	stringstream concat;
	string result;

	GetLogicalDriveStrings(256, dr_avail);
	while (*temp != NULL)
	{
		/*GetVolumeInformation(temp, volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName));
		concat << temp << " " << volumeName;
		result = concat.str();

		hddList.push_back(result);*/
		hddList.push_back(temp);

		temp += lstrlen(temp) + 1;
		}

	return hddList;
}