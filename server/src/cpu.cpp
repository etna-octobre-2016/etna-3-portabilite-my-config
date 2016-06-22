#include "../header/header.h"

Cpu *Cpu::getInstance()
{
	Cpu *cpu;

	#ifdef _WIN32
		cpu = new Cpuwin();
	#elif __APPLE__
		cpu = new Cpumac();
	#else 
		cpu = new Cpulinux();
	#endif 
	return cpu;
}
