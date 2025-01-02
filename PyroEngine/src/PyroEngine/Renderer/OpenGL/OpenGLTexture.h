#pragma once
#include "PyroEngine/Renderer/Texture.h"

namespace PyroEngine
{
	class OpenGLTexture : public Texture
	{
	private:
		FilePath m_FilePath;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
	public:
		OpenGLTexture(const FilePath& filePath);
		OpenGLTexture(uint32_t width, uint32_t height);
		virtual ~OpenGLTexture();

		uint32_t GetRendererID() const { return m_RendererID; }

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }
		virtual const FilePath& GetFilePath() const override { return m_FilePath; }

		virtual void SetData(void* data, uint32_t size) override;
		virtual void BindToSlot(uint32_t slot = 0) override;
	};
}