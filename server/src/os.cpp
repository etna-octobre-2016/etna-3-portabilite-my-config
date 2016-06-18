#include "../header/header.h"

Os *Os::getInstance()
{
  Os *os;

#ifdef _WIN32
  os = new Windowsos();
#elif __APPLE__
  os = new Macos();
#else 
  os = new Linuxos();
#endif 
  return os;
}
