#include "../header/header.h"

using namespace std;

/**
* Converts normal string to unicode string
* @param  str  a normal string
* @return      the unicode string
*/
inline std::wstring s2ws(const std::string& str)
{
  wstring output;

  utf8::utf8to32(str.begin(), str.end(), back_inserter(output));
  return output;
}

/**
 * Converts unicode string to normal string
 * @param  wstr an unicode string
 * @return      the normal string
 */
string ws2s(const std::wstring& wstr)
{
  string output;

  utf8::utf32to8(wstr.begin(), wstr.end(), back_inserter(output));
  return output;
}
void api_cpu_handler(const shared_ptr<restbed::Session> session)
{
  Cpu *cpu;
  JSONObject obj;
  JSONValue *output;
  wstring cpuModel;
  double cpuCount;
  double cpuFrequency;

  cpu = Cpu::getInstance();
  cpuModel = s2ws(cpu->getCpuInfo());
  cpuCount = cpu->getCoresCount();
  cpuFrequency = cpu->getFreq();
  obj[L"model"] = new JSONValue(cpuModel);
  obj[L"count"] = new JSONValue(cpuCount);
  obj[L"frequency"] = new JSONValue(cpuFrequency);
  output = new JSONValue(obj);
  session->close(restbed::OK, ws2s(output->Stringify()), { { "Content-Type", "application/json" } });
}
void api_hdd_handler(const shared_ptr<restbed::Session> session)
{
  Hdd *hdd;
  JSONArray devices;
  JSONObject obj;
  JSONObject deviceData;
  JSONValue *output;
  double hddTotal;
  double hddUsage;
  vector<string> hddDevices;

  hdd = Hdd::getInstance();
  hddTotal = hdd->getTotalCapacity();
  hddUsage = hdd->getUsedCapacity();
  hddDevices = hdd->getListHardDrive();
  obj[L"total"] = new JSONValue(hddTotal);
  obj[L"usage"] = new JSONValue(hddUsage);
  for (vector<string>::iterator it = hddDevices.begin(); it != hddDevices.end(); ++it)
  {
    deviceData[L"name"] = new JSONValue(s2ws(*it));
    devices.push_back(new JSONValue(deviceData));
  }
  obj[L"devices"] = new JSONValue(devices);
  output = new JSONValue(obj);
  session->close(restbed::OK, ws2s(output->Stringify()), { { "Content-Type", "application/json" } });
}
void api_ram_handler(const shared_ptr<restbed::Session> session)
{
  Memory *memory;
  JSONObject obj;
  JSONValue *output;
  double memoryFreeSpace;
  double memoryTotalSpace;
  double memoryUsage;

  memory = Memory::getInstance();
  memoryFreeSpace = memory->getFreeRam();
  memoryTotalSpace = memory->getTotalRam();
  memoryUsage = memory->getPourcentRam();
  obj[L"free"] = new JSONValue(memoryFreeSpace);
  obj[L"total"] = new JSONValue(memoryTotalSpace);
  obj[L"usage"] = new JSONValue(memoryUsage);
  output = new JSONValue(obj);
  session->close(restbed::OK, ws2s(output->Stringify()), { { "Content-Type", "application/json" } });
}
void api_os_handler(const shared_ptr<restbed::Session> session)
{
  Os *os;
  JSONObject obj;
  JSONValue *output;
  wstring osName;
  double osArchitecture;

  os = Os::getInstance();
  osName = s2ws(os->getName());
  osArchitecture = os->getArchitecture();
  obj[L"name"] = new JSONValue(osName);
  obj[L"architecture"] = new JSONValue(osArchitecture);
  output = new JSONValue(obj);
  session->close(restbed::OK, ws2s(output->Stringify()), { { "Content-Type", "application/json" } });
}
int main()
{
/*
  Hdd *ptr;
  LinuxHdd hdd;
  ptr = &hdd;

vector<string> v = ptr->getListHardDrive();

  cout << "test " << endl;
  for(int i = 0; i < v.size();i++)
      cout << v[i] << endl;
  cout << "fin" << endl;
*/
  Webservice w;

  w.addRoute("GET", "/cpu", api_cpu_handler);
  w.addRoute("GET", "/hdd", api_hdd_handler);
  w.addRoute("GET", "/os", api_os_handler);
  w.addRoute("GET", "/ram", api_ram_handler);
  w.setPort(3000);
  w.start();

  return 0;
}
