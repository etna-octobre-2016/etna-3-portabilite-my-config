#include "../header/header.h"

using namespace restbed;
using namespace std;

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
void api_cpu_handler(const shared_ptr<Session> session)
{
  JSONObject  obj;
  JSONValue   *output;
  wstring     outputString;
  ostringstream stringStream;


  obj[L"route"] = new JSONValue(L"Je suis une fougère");
  output = new JSONValue(obj);
  outputString = output->Stringify();
  stringStream << outputString.length();
  session->close(OK, ws2s(outputString), { { "Content-Type", "application/json" } });
}
void api_hdd_handler(const shared_ptr<Session> session)
{
  session->close(OK, "hdd", { { "Content-Length", "3" } });
}
void api_ram_handler(const shared_ptr<Session> session)
{
  session->close(OK, "ram", { { "Content-Length", "3" } });
}
void api_os_handler(const shared_ptr<Session> session)
{
  session->close(OK, "os", { { "Content-Length", "2" } });
}
void api_init()
{
  auto cpuResource = make_shared<Resource>();
  cpuResource->set_path("/cpu");
  cpuResource->set_method_handler("GET", api_cpu_handler);

  auto hddResource = make_shared<Resource>();
  hddResource->set_path("/hdd");
  hddResource->set_method_handler("GET", api_hdd_handler);

  auto ramResource = make_shared<Resource>();
  ramResource->set_path("/ram");
  ramResource->set_method_handler("GET", api_ram_handler);

  auto osResource = make_shared<Resource>();
  osResource->set_path("/os");
  osResource->set_method_handler("GET", api_os_handler);

  auto settings = make_shared<Settings>();
  settings->set_port(1337);
  settings->set_default_header("Connection", "close");

  Service service;
  service.publish(cpuResource);
  service.publish(hddResource);
  service.publish(ramResource);
  service.publish(osResource);
  service.start(settings);
}
int main()
{
  //api_init();


    /*Ios ios;
    cout << ios.*/
    Os *ptr_os;
    Cpu *ptr_cpu;
    Memory *ptr_mem;
	Hdd *ptr_hdd;
    #ifdef _WIN32
        Windowsos os;
        Cpuwin cpu;
        Memorywin mem;
		Winhdd hdd;
    #elif __APPLE__
        Macos os;
        Cpumac cpu;
        Memorymac mem;
		Machdd hdd;
    #else
        Linuxos os;
        Cpulinux cpu;
        Memorylinux mem;
		Linuxhdd hdd;
    #endif
    ptr_os = &os;
    ptr_cpu = &cpu;
    ptr_mem = &mem;
	ptr_hdd = &hdd;
    
    cout << "CPU informations:" << endl;
    cout << ptr_cpu->getCpuInfo() << endl;
    cout << "Number of Cores: " << cpu.getCoresCount() << endl;
    cout << endl;
    cout << "OS informations:" << endl;
    cout << ptr_os->getName() << endl;
    cout << "architecture: " << ptr_os->getArchitecture() << " bits" << endl;
    cout << endl;
    cout << "Ram informations:" << endl;
    cout << "Total RAM: " << ptr_mem->getTotalRam() << " KB" << endl;
    cout << "Free RAM: " << ptr_mem->getFreeRam() << " KB" << endl;
    cout << ptr_mem->getPourcentRam() << "% used Ram" << endl; 
    cout << endl;
    cout << "HDD informations: " << endl;
    cout << "TOTAL: " << ptr_hdd->getTotalCapacity() << " MO" << endl;
	cout << "Used: " << ptr_hdd->getUsedCapacity() << " MO" << endl;
	cout << "List: " << endl;

	for (size_t i = 0, size = ptr_hdd->getListHardDrive().size(); i < size; ++i)
	{
		cout << ptr_hdd->getListHardDrive()[i] << endl;
	}
	

	system("pause");
    return 0;
}

/*
#ifdef _WIN32
        int dr_type = 99;
        char dr_avail[256];
        char *temp = dr_avail;
        
        GetLogicalDriveStrings(256, dr_avail);
        __int64 ttlspc, frspc;
        while(*temp != NULL)
        {
            dr_type = GetDriveType(temp);
            switch(dr_type) {
                case DRIVE_UNKNOWN:
                    cout << temp <<  " Unknown Drive type" << endl;
                    break;
                case DRIVE_NO_ROOT_DIR:
                    cout << temp <<  " Drive is invalid" << endl;
                    break;
                case DRIVE_REMOVABLE:
                    cout << temp <<  " Removable Drive" << endl;
                    break;
                case DRIVE_FIXED:
                    cout << temp <<  " Hard disk" << endl;
                    break;
                case DRIVE_REMOTE:
                    cout << temp <<  " Remote Drive (Network)" << endl;
                    break;
                case DRIVE_CDROM:
                    cout << temp <<  " CD-ROM/ DVD-Rom" << endl;
                    break;
                case DRIVE_RAMDISK:
                    cout << temp <<  " Ram drive" << endl;
                    break;
            }

        }
        
        
        return 0;
    }
*/