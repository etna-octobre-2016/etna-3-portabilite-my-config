#include "../header/header.h"

using namespace std;

/**
* Converts normal string to unicode string
* @param  str  a normal string
* @return      the unicode string
*/
inline std::wstring s2ws(const std::string& str)
{
	typedef std::codecvt_utf8<wchar_t> convert_typeX;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

/**
 * Converts unicode string to normal string
 * @param  wstr an unicode string
 * @return      the normal string
 */
string ws2s(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}
void api_cpu_handler(const shared_ptr<restbed::Session> session)
{
  Cpu *cpu;
  JSONObject  obj;
  JSONValue   *output;
  wstring     outputString;
  ostringstream stringStream;
  wstring cpuModel;
  double cpuCount;

  cpu = Cpu::getInstance();
  cpuModel = s2ws(cpu->getCpuInfo());
  cpuCount = cpu->getCoresCount();
  obj[L"model"] = new JSONValue(cpuModel);
  obj[L"count"] = new JSONValue(cpuCount);
  output = new JSONValue(obj);
  outputString = output->Stringify();
  stringStream << outputString.length();
  session->close(restbed::OK, ws2s(outputString), { { "Content-Type", "application/json" } });
}
void api_hdd_handler(const shared_ptr<restbed::Session> session)
{
  session->close(restbed::OK, "hdd", { { "Content-Length", "3" } });
}
void api_ram_handler(const shared_ptr<restbed::Session> session)
{
  session->close(restbed::OK, "ram", { { "Content-Length", "3" } });
}
void api_os_handler(const shared_ptr<restbed::Session> session)
{
  session->close(restbed::OK, "os", { { "Content-Length", "2" } });
}
int main()
{
  Webservice w;

  w.addRoute("GET", "/cpu", api_cpu_handler);
  w.addRoute("GET", "/hdd", api_hdd_handler);
  w.addRoute("GET", "/os", api_os_handler);
  w.addRoute("GET", "/ram", api_ram_handler);
  w.setPort(3000);
  w.start();
  return 0;
}
