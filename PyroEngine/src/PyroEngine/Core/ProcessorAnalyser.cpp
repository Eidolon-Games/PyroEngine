#include "PyroEnginePCH.h"
#include "ProcessorAnalyser.h"
#include "Core.h"
#include <cstring>
#if defined PYRO_PLATFORM_WINDOWS
#include <intrin.h>
#endif

namespace PyroEngine
{
	std::string ProcessorAnalyser::s_ProcessorName = "";
	bool ProcessorAnalyser::s_IsIntel = false;
	bool ProcessorAnalyser::s_IsAMD = false;

	void ProcessorAnalyser::CPU_ID(int* cpuInfo, int cpuInfoType)
	{
#ifdef PYRO_PLATFORM_WINDOWS
		__cpuid(cpuInfo, cpuInfoType);
#else
		asm("cpuid" : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]), "=d" (cpuInfo[3])
				: "a" (cpuInfoType), "c" (0));
#endif
	}

	void ProcessorAnalyser::Analyse()
	{
		int cpuInfo[4] = { 0, 0, 0, 0 };

		//Set highest valid function ID
		CPU_ID(cpuInfo, 0);

		//Capture vendor string
		char vendor[32];
		std::memset(vendor, 0, sizeof(vendor));
		*reinterpret_cast<int*>(vendor) = cpuInfo[1];
		*reinterpret_cast<int*>(vendor + 4) = cpuInfo[3];
		*reinterpret_cast<int*>(vendor + 8) = cpuInfo[2];
		s_IsIntel = !std::strcmp(vendor, "GenuineIntel");
		s_IsAMD = !std::strcmp(vendor, "AuthenticAMD");

		//Capture brand string
		char brand[64];
		std::memset(brand, 0, sizeof(brand));
		CPU_ID(cpuInfo, 0x80000000);
		if (cpuInfo[0] >= 0x80000004)
		{
			CPU_ID(cpuInfo, 0x80000002);
			std::memcpy(brand, cpuInfo, sizeof(cpuInfo));
			CPU_ID(cpuInfo, 0x80000003);
			std::memcpy(brand + 16, cpuInfo, sizeof(cpuInfo));
			CPU_ID(cpuInfo, 0x80000004);
			std::memcpy(brand + 32, cpuInfo, sizeof(cpuInfo));
			s_ProcessorName = brand;
		}
	}
}