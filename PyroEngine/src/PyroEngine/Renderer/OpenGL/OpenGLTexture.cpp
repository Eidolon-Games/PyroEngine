#include "PyroEnginePCH.h"
#include "OpenGLTexture.h"
#include "PyroEngine/Core/Core.h"
#include "glad/glad.h"

namespace PyroEngine
{
	OpenGLTexture::OpenGLTexture(const std::filesystem::path& filePath)
		: m_FilePath(filePath)
	{
		uint8_t* data = nullptr; //Here will be the data from the image file
		PYRO_ASSERT(data, "Failed to load Image!");
		m_Width = 0;
		m_Height = 0;

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, GL_RGBA8, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);

		delete[] data;
	}

	OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height)
		: m_Width(width), m_Height(height)
	{

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, GL_RGBA8, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture::SetData(void* data, uint32_t size)
	{
		PYRO_ASSERT(size == m_Width * m_Height * 4, "Data must cover the entire Texture");

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
}