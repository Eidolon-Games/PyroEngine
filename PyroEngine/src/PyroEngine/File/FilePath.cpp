#include "PyroEnginePCH.h"
#include "FilePath.h"

namespace PyroEngine
{
	FilePath::FilePath()
		: m_Path()
	{
	}

	FilePath::FilePath(const char* c_str)
		: m_Path(std::filesystem::absolute(c_str))
	{
	}

	FilePath::FilePath(const std::string& std_str)
		: m_Path(std::filesystem::absolute(std_str))
	{
	}

	FilePath::FilePath(const std::filesystem::path& std_path)
		: m_Path(std::filesystem::absolute(std_path))
	{
	}

	FilePath::~FilePath()
	{
	}

	std::filesystem::path FilePath::GetStdPath()
	{
		return m_Path;
	}

	bool FilePath::SetStdPath(const std::filesystem::path& std_path)
	{
		std::error_code ec;
		std::filesystem::path absolutePath = std::filesystem::absolute(std_path, ec);
		if (ec.value() == 0)
		{
			m_Path = absolutePath;
			return true;
		}
		
		return false;
	}

	std::string FilePath::GetStrPath()
	{
		return m_Path.string();
	}

	bool FilePath::SetStrPath(const std::string& std_str)
	{
		std::error_code ec;
		std::filesystem::path absolutePath = std::filesystem::absolute(std_str, ec);
		if (ec.value() == 0)
		{
			m_Path = absolutePath;
			return true;
		}

		return false;
	}

	bool FilePath::Exists()
	{
		std::error_code ec;
		return std::filesystem::exists(m_Path, ec);
	}

	bool FilePath::CreateAsFile()
	{
		if (!Exists())
		{
			std::fstream fileStream;
			fileStream.open(m_Path, std::ios::out);
			fileStream.close();
			return true;
		}

		return false;
	}

	bool FilePath::CreateAsDirectory()
	{
		if (!Exists())
		{
			std::error_code ec;
			return std::filesystem::create_directory(m_Path, ec);
		}

		return false;
	}

	bool FilePath::Delete()
	{
		std::error_code ec;
		uintmax_t numFilesAndDirectories = std::filesystem::remove_all(m_Path, ec);
		return ec.value() == 0 && numFilesAndDirectories != 0;
	}
}