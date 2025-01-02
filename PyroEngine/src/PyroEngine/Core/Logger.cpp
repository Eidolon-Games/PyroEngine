#include "PyroEnginePCH.h"
#include "Logger.h"

namespace PyroEngine
{
	FileStreamer Logger::s_LogFile;
	void (*Logger::s_LoggerFunctionCallback)(LoggerChannel, const std::string&) = nullptr;

	void Logger::DecodeAndAppendLogArgument(std::vector<std::string>& strings)
	{
		//Is supposed to not do anything
	}

	bool Logger::TurnOnFileLogging()
	{
		FilePath path = "PyroLog.txt";
		path.Delete();
		bool success = s_LogFile.Open(path);
		return success;
	}

	void Logger::TurnOffFileLogging()
	{
		s_LogFile.Close();
	}

	bool Logger::GetFileLoggingStatus()
	{
		return s_LogFile.IsOpen();
	}

	void Logger::SetLoggerCallback(void(*callback)(LoggerChannel, const std::string&))
	{
		s_LoggerFunctionCallback = callback;
	}

	void(*Logger::GetLoggerCallback())(LoggerChannel, const std::string&)
	{
		return s_LoggerFunctionCallback;
	}
}