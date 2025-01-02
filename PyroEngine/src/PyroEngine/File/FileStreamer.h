#pragma once
#include "FilePath.h"
#include <fstream>

namespace PyroEngine
{
	class FileStreamer
	{
	private:
		FilePath m_FilePath; //The path to where the currently open file is on the host system
		std::fstream m_FileStream; //The output stream used to open, close and write to files
	public:
		FileStreamer();
		~FileStreamer();

		//Returns the absolute path of the currently open file. If no file is open, then it will return the current working directory
		FilePath GetFilePath() const;

		//Opens a file on the host system. An optional flag can be set if the file should be created if it doesnt already exist. If a file is already currently open then it will close that file before attempting to open the new one. The read/write indicator will be set at the very beginning of the file so that the next retrived byte will be the first one in the file and the next written byte will override the first one in the file. Returns whether or not the file has been successfully opened
		bool Open(const FilePath& path, bool createIfDoesntExist = true);
		//Closes the currently open file. If no file is open, then this function will not do anything
		void Close();
		//Returns whether or not a file is currently open
		bool IsOpen() const noexcept;

		//Sets the position of the read/write indicator such that the next read/write operation is from that position
		void SeekPosition(size_t pos);
		//Retrieves the current position of the read/write indicator within the currently open file
		size_t GetPosition();

		//Sets the position of the read/write indicator such that the next read/write operation is at the very start of the currently open file
		void GoToStart();
		//Sets the position of the read/write indicator such that the next read/write operation is at the very end of the currently open file
		void GoToEnd();

		//Writes an 8-bit signed integer (little-endian) to the current position within the file and increments said position by 1
		void WriteInt8LE(int8_t integer);
		//Writes a 16-bit signed integer (little-endian) to the current position within the file and increments said position by 2
		void WriteInt16LE(int16_t integer);
		//Writes a 32-bit signed integer (little-endian) to the current position within the file and increments said position by 4
		void WriteInt32LE(int32_t integer);
		//Writes a 64-bit signed integer (little-endian) to the current position within the file and increments said position by 8
		void WriteInt64LE(int64_t integer);

		//Writes an 8-bit unsigned integer (little-endian) to the current position within the file and increments said position by 1
		void WriteUInt8LE(uint8_t integer);
		//Writes a 16-bit unsigned integer (little-endian) to the current position within the file and increments said position by 2
		void WriteUInt16LE(uint16_t integer);
		//Writes a 32-bit unsigned integer (little-endian) to the current position within the file and increments said position by 4
		void WriteUInt32LE(uint32_t integer);
		//Writes a 64-bit unsigned integer (little-endian) to the current position within the file and increments said position by 8
		void WriteUInt64LE(uint64_t integer);

		//Writes an 8-bit signed integer (big-endian) to the current position within the file and increments said position by 1
		void WriteInt8BE(int8_t integer);
		//Writes a 16-bit signed integer (big-endian) to the current position within the file and increments said position by 2
		void WriteInt16BE(int16_t integer);
		//Writes a 32-bit signed integer (big-endian) to the current position within the file and increments said position by 4
		void WriteInt32BE(int32_t integer);
		//Writes a 64-bit signed integer (big-endian) to the current position within the file and increments said position by 8
		void WriteInt64BE(int64_t integer);

		//Writes an 8-bit unsigned integer (big-endian) to the current position within the file and increments said position by 1
		void WriteUInt8BE(uint8_t integer);
		//Writes a 16-bit unsigned integer (big-endian) to the current position within the file and increments said position by 2
		void WriteUInt16BE(uint16_t integer);
		//Writes a 32-bit unsigned integer (big-endian) to the current position within the file and increments said position by 4
		void WriteUInt32BE(uint32_t integer);
		//Writes a 64-bit unsigned integer (big-endian) to the current position within the file and increments said position by 8
		void WriteUInt64BE(uint64_t integer);

		//Writes a string to the file ignoring the null character at the end, then increments the positional indicator by the string's length
		void WriteString(const std::string& str);
		//Writes a string to the file including the null character at the end, then increments the positional indicator by the string's length
		void WriteStringWithNull(const std::string& str);

		//Retrieves the next 8-bit signed integer (little-endian) from the current position within the file and increments said position by 1
		int8_t ReadInt8LE();
		//Retrieves the next 16-bit signed integer (little-endian) from the current position within the file and increments said position by 2
		int16_t ReadInt16LE();
		//Retrieves the next 32-bit signed integer (little-endian) from the current position within the file and increments said position by 4
		int32_t ReadInt32LE();
		//Retrieves the next 64-bit signed integer (little-endian) from the current position within the file and increments said position by 8
		int64_t ReadInt64LE();

		//Retrieves the next 8-bit unsigned integer (little-endian) from the current position within the file and increments said position by 1
		uint8_t ReadUInt8LE();
		//Retrieves the next 16-bit unsigned integer (little-endian) from the current position within the file and increments said position by 2
		uint16_t ReadUInt16LE();
		//Retrieves the next 32-bit unsigned integer (little-endian) from the current position within the file and increments said position by 4
		uint32_t ReadUInt32LE();
		//Retrieves the next 64-bit unsigned integer (little-endian) from the current position within the file and increments said position by 8
		uint64_t ReadUInt64LE();

		//Retrieves the next 8-bit signed integer (big-endian) from the current position within the file and increments said position by 1
		int8_t ReadInt8BE();
		//Retrieves the next 16-bit signed integer (big-endian) from the current position within the file and increments said position by 2
		int16_t ReadInt16BE();
		//Retrieves the next 32-bit signed integer (big-endian) from the current position within the file and increments said position by 4
		int32_t ReadInt32BE();
		//Retrieves the next 64-bit signed integer (big-endian) from the current position within the file and increments said position by 8
		int64_t ReadInt64BE();

		//Retrieves the next 8-bit unsigned integer (big-endian) from the current position within the file and increments said position by 1
		uint8_t ReadUInt8BE();
		//Retrieves the next 16-bit unsigned integer (big-endian) from the current position within the file and increments said position by 2
		uint16_t ReadUInt16BE();
		//Retrieves the next 32-bit unsigned integer (big-endian) from the current position within the file and increments said position by 4
		uint32_t ReadUInt32BE();
		//Retrieves the next 64-bit unsigned integer (big-endian) from the current position within the file and increments said position by 8
		uint64_t ReadUInt64BE();

		//Retrives the next string of the length specified starting from the current position within the file and increments said position by the length specified
		std::string ReadString(size_t length);
		//Retrieves the next string from the current position within the file. This function will stop as soon as the end of the file is reached or until a null character has been reached. It will increment the current position within the file by the amount of characters retrieved
		std::string ReadStringUntilNull();
	};
}