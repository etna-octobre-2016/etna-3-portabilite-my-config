#include "../header/header.h"

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
void api_cpu_handler(const shared_ptr<restbed::Session> session)
{
  JSONObject  obj;
  JSONValue   *output;
  wstring     outputString;
  ostringstream stringStream;


  obj[L"route"] = new JSONValue(L"Je suis une fougère");
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
void api_init()
{
  Webservice w;

  w.addRoute("GET", "/cpu", api_cpu_handler);
  w.addRoute("GET", "/hdd", api_hdd_handler);
  w.addRoute("GET", "/os", api_os_handler);
  w.addRoute("GET", "/ram", api_ram_handler);
  w.setPort(3000);
  w.start();
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