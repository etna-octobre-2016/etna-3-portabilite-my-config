#include "../header/header.h"


using namespace std;

int main()
{
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
    #ifdef _WIN32
        Windowsos os;
    #elif __APPLE__
        Macos os;
    #else
        Linuxos os;
    #endif
    ptr_os = &os;
    
    Cpu cpu;
    Cpu *ptr_cpu;
    ptr_cpu = &cpu;
    cout << "CPU informations:" << endl;
    cout << ptr_cpu->getCpuInfo() << endl;
    cout << "Number of Cores: " << cpu.getCoresCount() << endl;
    cout << endl;
    cout << "OS informations:" << endl;
    cout << ptr_os->getName() << endl;
    cout << "architecture: " << ptr_os->getArchitecture() << " bits" << endl;
    Memory memory;
    cout << endl;
    cout << "Ram informations:" << endl;
    cout << "Total RAM: " << memory.getTotalRam() << " KB" << endl;
    cout << "Free RAM: " << memory.getFreeRam() << " KB" << endl;
    cout << memory.getPourcentRam() << "% used Ram" << endl; 
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