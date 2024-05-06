#pragma once
#include <iostream>

#define PYRO_VERSION_MAJOR 0
#define PYRO_VERSION_MINOR 0
#define PYRO_VERSION_PATCH 0

#if defined PYRO_CONFIG_DEBUG
#define PYRO_ASSERTS_ENABLED
#else
#define PYRO_ASSERTS_DISABLED
#endif

#if defined PYRO_ASSERTS_ENABLED
#if defined PYRO_PLATFORM_WINDOWS
#define PYRO_ASSERT(x, message) { if(!(x)) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#define PYRO_REVERSE_ASSERT(x, message) { if(x) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#endif
#if defined PYRO_PLATFORM_LINUX
#define PYRO_ASSERT(x, message) { if(!(x)) { std::cout << "Assertion Failed: " << message << "\n"; std::exit(1); } }
#define PYRO_REVERSE_ASSERT(x, message) { if(x) { std::cout << "Assertion Failed: " << message << "\n"; std::exit(1); } }
#endif
#else
#define PYRO_ASSERT(x, message) 
#define PYRO_REVERSE_ASSERT(x, message) 
#endif

#define PYRO_BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)
#define PYRO_BIT_FIELD(x) (1 << x)

#define PYRO_CPU_MMX_BIT PYRO_BIT_FIELD(23)
#define PYRO_CPU_SSE_BIT PYRO_BIT_FIELD(25)
#define PYRO_CPU_SSE2_BIT PYRO_BIT_FIELD(26)
#define PYRO_CPU_SSE3_BIT PYRO_BIT_FIELD(0)
#define PYRO_CPU_SSSE3_BIT PYRO_BIT_FIELD(9)
#define PYRO_CPU_SSE41_BIT PYRO_BIT_FIELD(19)
#define PYRO_CPU_SSE42_BIT PYRO_BIT_FIELD(20)
#define PYRO_CPU_AVX_BIT PYRO_BIT_FIELD(28)
#define PYRO_CPU_AVX2_BIT PYRO_BIT_FIELD(5)
#define PYRO_CPU_FMA_BIT PYRO_BIT_FIELD(12)
#define PYRO_CPU_AVX512F_BIT PYRO_BIT_FIELD(16)
#define PYRO_CPU_AVX512PF_BIT PYRO_BIT_FIELD(26)
#define PYRO_CPU_AVX512ER_BIT PYRO_BIT_FIELD(27)
#define PYRO_CPU_AVX512CD_BIT PYRO_BIT_FIELD(28)