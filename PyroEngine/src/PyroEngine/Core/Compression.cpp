#include "PyroEnginePCH.h"
#include "Compression.h"

namespace PyroEngine
{
	uint8_t* Compression::CompressRLE(uint8_t* bytes, size_t sizeOfBytes, size_t sizeOfElements, size_t sizeOfDesiredRunLength, size_t* returnedLength)
	{
		return nullptr;
	}

	uint8_t* Compression::DecompressRLE(uint8_t* bytes, size_t sizeOfBytes, size_t sizeOfElements, size_t sizeOfRunLength, size_t* returnedLength)
	{
		uint8_t* output = nullptr;
		size_t bytesNeededForAllocation = 0;

		if (bytes == nullptr || sizeOfBytes < sizeOfElements + sizeOfRunLength || sizeOfElements == 0 || sizeOfRunLength == 0 || returnedLength == nullptr)
			return nullptr;

		bool isValid = true;
		for (size_t i = 0; i < sizeOfBytes; )
		{
			if (i + sizeOfRunLength >= sizeOfBytes)
			{
				isValid = false;
				i = sizeOfBytes;
			}
			else
			{
				uint8_t* forwardedPtr = bytes + i;
				size_t runLength = 0;
				for (size_t j = 0; j < sizeOfRunLength; j++)
				{
					runLength += ((size_t)(*forwardedPtr) * ((size_t)1 << (j * (size_t)8)));
					forwardedPtr++;
				}
				size_t highestBit = ((size_t)1 << ((sizeOfRunLength * (size_t)8) - (size_t)1));
				bool isRunning = false;
				if (runLength >= highestBit)
				{
					runLength -= highestBit;
					isRunning = true;
				}
				runLength++;
				bytesNeededForAllocation += sizeOfElements * runLength;
				if (isRunning)
					i += sizeOfElements + sizeOfRunLength;
				else
				{
					i += sizeOfRunLength;
					i += sizeOfElements * runLength;
				}
				if (i > sizeOfBytes)
				{
					isValid = false;
					i = sizeOfBytes;
				}
			}
		}

		if (!isValid)
			return nullptr;

		output = new uint8_t[bytesNeededForAllocation];
		size_t outputPlacementIndex = 0;

		for (size_t i = 0; i < sizeOfBytes; )
		{
			uint8_t* forwardedPtr = bytes + i;
			size_t runLength = 0;
			for (size_t j = 0; j < sizeOfRunLength; j++)
			{
				runLength += ((size_t)(*forwardedPtr) * ((size_t)1 << (j * (size_t)8)));
				forwardedPtr++;
			}
			size_t highestBit = ((size_t)1 << ((sizeOfRunLength * (size_t)8) - (size_t)1));
			bool isRunning = false;
			if (runLength >= highestBit)
			{
				runLength -= highestBit;
				isRunning = true;
			}
			runLength++;
			if (isRunning)
			{
				for (size_t k = 0; k < runLength; k++)
				{
					for (size_t l = 0; l < sizeOfElements; l++)
					{
						output[outputPlacementIndex] = *(forwardedPtr + l);
						outputPlacementIndex++;
					}
				}
			}
			else
			{
				for (size_t k = 0; k < runLength; k++)
				{
					for (size_t l = 0; l < sizeOfElements; l++)
					{
						output[outputPlacementIndex] = *(forwardedPtr + (k * sizeOfElements) + l);
						outputPlacementIndex++;
					}
				}
			}
			if (isRunning)
				i += sizeOfElements + sizeOfRunLength;
			else
			{
				i += sizeOfRunLength;
				i += sizeOfElements * runLength;
			}
		}

		*returnedLength = bytesNeededForAllocation;
		return output;
	}
}