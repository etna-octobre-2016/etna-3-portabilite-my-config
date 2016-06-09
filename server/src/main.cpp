#include "../header/header.h"

using namespace restbed;
using namespace std;

void api_cpu_handler(const shared_ptr<Session> session)
{
  session->close(OK, "cpu", { { "Content-Length", "3" } });
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
  api_init();
    /* Connexion */
    /*Socket sck;
    sck.run();*/
    
   /* typedef vector<string> str_vec_t;
    str_vec_t v1;    
    v1.push_back("test");
    v1.push_back("test2");
    v1.push_back("test3");
    
    for (auto iterator it = v1.begin(); it != v1.end(); ++it)
    {
        string &el = *it;
        cout << el << endl;
    }
    */
    
    /*json::value obj
    obj[L"key1"] = json::value::boolean(false);
    obj[L"key2"] = json::value::number(44);
    obj[L"key3"] = json::value::string(U("str"));
    
    for(auto iter = obj.cbegin(); iter != obj.cend(); ++iter)
    {
        const json::value &str = iter->first;
        const json::value &v = iter->second;
        
        cout << L"String: " << str.as_string() << L", Value: " << v.to_string() << endl;
    }*/
    
    /*Ios ios;
    cout << ios.*/
    Os *ptr_os;
    Cpu *ptr_cpu;
    Memory *ptr_mem;
    #ifdef _WIN32
        Windowsos os;
        Cpuwin cpu;
        Memorywin mem;
    #elif __APPLE__
        Macos os;
        Cpumac cpu;
        Memorymac mem;
    #else
        Linuxos os;
        Cpulinux cpu;
        Memorylinux mem;
    #endif
    ptr_os = &os;
    ptr_cpu = &cpu;
    ptr_mem = &mem;
    
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
    Hdd hdd;
    cout << "HDD informations: " << endl;
    cout << "TOTAL : " << hdd.getTotalCapacity() << " MO" << endl;   
    
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
            GetDiskFreeSpaceEx(temp, 0, (PULARGE_INTEGER)&ttlspc, (PULARGE_INTEGER)&frspc);
            cout << "TOTAL : " << ttlspc/1024/1024 << " MO" << endl;
            cout << "libre : " << frspc/1024/1024 << " MO" << endl;
            temp += lstrlen(temp) + 1;
        }
        
        
        return 0;
    }
*/