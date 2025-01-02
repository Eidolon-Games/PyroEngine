#pragma once
#include <filesystem>

namespace PyroEngine
{
	class FilePath
	{
	private:
		std::filesystem::path m_Path;
	public:
		FilePath();
		FilePath(const char* c_str);
		FilePath(const std::string& std_str);
		FilePath(const std::filesystem::path& std_path);
		~FilePath();

		std::filesystem::path GetStdPath();
		bool SetStdPath(const std::filesystem::path& std_path);

		std::string GetStrPath();
		bool SetStrPath(const std::string& std_str);

		bool Exists();
		bool CreateAsFile();
		bool CreateAsDirectory();
		bool Delete();
	};
}