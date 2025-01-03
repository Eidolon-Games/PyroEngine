#pragma once
#include <stdint.h>

namespace PyroEngine
{
	class Compression
	{
	public:
		//Compresses a series of bytes using the RLE encoding method (TARGA Spec). There are multiple versions of RLE that use slighly different setup to the version used in this function which uses an escape bit to determine whether the next series of elements are a run or not. Returns nullptr on failure otherwise returns a pointer to the compressed series of bytes
		static uint8_t* CompressRLE(uint8_t* bytes, size_t sizeOfBytes, size_t sizeOfElements, size_t sizeOfDesiredRunLength, size_t* returnedLength);
		//Decompresses a series of bytes that has been compressed using the RLE encoding method (TARGA Spec). There are multiple versions of RLE that use slighly different setup to the version used in this function which uses an escape bit to determine whether the next series of elements are a run or not. Returns nullptr on failure otherwise returns a pointer to the decompressed series of bytes
		static uint8_t* DecompressRLE(uint8_t* bytes, size_t sizeOfBytes, size_t sizeOfElements, size_t sizeOfRunLength, size_t* returnedLength);
	};
}