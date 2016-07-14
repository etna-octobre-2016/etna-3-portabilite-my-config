#include "../header/header.h"

Memory *Memory::getInstance()
{
  Memory *memory;

#ifdef _WIN32
  memory = new Memorywin();
#elif __APPLE__
  memory = new Memorymac();
#else 
  memory = new Memorylinux();
#endif 
  return memory;
}
