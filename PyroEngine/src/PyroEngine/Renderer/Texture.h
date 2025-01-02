#pragma once
#include <string>
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual const FilePath& GetFilePath() const = 0;

		virtual void SetData(void* data, uint32_t size) = 0;
		virtual void BindToSlot(uint32_t slot = 0) = 0;

		static Texture* Create(const FilePath& filePath);
		static Texture* Create(uint32_t width, uint32_t height);
	};
}