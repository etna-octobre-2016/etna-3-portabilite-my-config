#include "../header/header.h"

Hdd *Hdd::getInstance()
{
  Hdd *hdd;

#ifdef _WIN32
  hdd = new Winhdd();
#elif __APPLE__
  hdd = new Machdd();
#else 
  hdd = new LinuxHdd();
#endif 
  return hdd;
}
