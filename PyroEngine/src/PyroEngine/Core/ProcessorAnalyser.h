#pragma once
#include <string>

namespace PyroEngine
{
	class ProcessorAnalyser
	{
	private:
		static void CPU_ID(int* cpuInfo, int cpuInfoType);
	public:
		static std::string s_ProcessorName;
		static bool s_IsIntel;
		static bool s_IsAMD;

		static void Analyse();
	};
}