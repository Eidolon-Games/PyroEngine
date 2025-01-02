#include "PyroEnginePCH.h"
#include "FileStreamer.h"

namespace PyroEngine
{
	FileStreamer::FileStreamer()
		: m_FilePath(), m_FileStream()
	{
	}

	FileStreamer::~FileStreamer()
	{
		m_FileStream.close();
	}

	FilePath FileStreamer::GetFilePath() const
	{
		return m_FilePath;
	}

	bool FileStreamer::Open(const FilePath& path, bool createIfDoesntExist)
	{
		m_FileStream.close();
		m_FilePath = path;
		m_FileStream.open(m_FilePath.GetStdPath(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
		if (!m_FileStream.is_open())
		{
			if (createIfDoesntExist)
			{
				m_FileStream.open(m_FilePath.GetStdPath(), std::ios::out);
				m_FileStream.close();
				m_FileStream.open(m_FilePath.GetStdPath(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
			}
			else
			{
				m_FilePath = FilePath();
				return false;
			}
		}
		m_FileStream.seekp(0, std::ios::beg);
		return true;
	}

	void FileStreamer::Close()
	{
		m_FileStream.close();
	}

	bool FileStreamer::IsOpen() const noexcept
	{
		return m_FileStream.is_open();
	}

	void FileStreamer::SeekPosition(size_t pos)
	{
		m_FileStream.seekp(pos, std::ios::beg);
	}

	size_t FileStreamer::GetPosition()
	{
		return m_FileStream.tellp();
	}

	void FileStreamer::GoToStart()
	{
		m_FileStream.seekp(0, std::ios::beg);
	}

	void FileStreamer::GoToEnd()
	{
		m_FileStream.seekp(0, std::ios::end);
	}

	void FileStreamer::WriteInt8LE(int8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileStreamer::WriteInt16LE(int16_t integer)
	{
		uint8_t bytes[2];
		bytes[0] = integer & 0x00FF;
		bytes[1] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileStreamer::WriteInt32LE(int32_t integer)
	{
		uint8_t bytes[4];
		bytes[0] = integer & 0x000000FF;
		bytes[1] = (integer & 0x0000FF00) >> 8;
		bytes[2] = (integer & 0x00FF0000) >> 16;
		bytes[3] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileStreamer::WriteInt64LE(int64_t integer)
	{
		uint8_t bytes[8];
		bytes[0] = integer & 0x00000000000000FF;
		bytes[1] = (integer & 0x000000000000FF00) >> 8;
		bytes[2] = (integer & 0x0000000000FF0000) >> 16;
		bytes[3] = (integer & 0x00000000FF000000) >> 24;
		bytes[4] = (integer & 0x000000FF00000000) >> 32;
		bytes[5] = (integer & 0x0000FF0000000000) >> 40;
		bytes[6] = (integer & 0x00FF000000000000) >> 48;
		bytes[7] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileStreamer::WriteUInt8LE(uint8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileStreamer::WriteUInt16LE(uint16_t integer)
	{
		uint8_t bytes[2];
		bytes[0] = integer & 0x00FF;
		bytes[1] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileStreamer::WriteUInt32LE(uint32_t integer)
	{
		uint8_t bytes[4];
		bytes[0] = integer & 0x000000FF;
		bytes[1] = (integer & 0x0000FF00) >> 8;
		bytes[2] = (integer & 0x00FF0000) >> 16;
		bytes[3] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileStreamer::WriteUInt64LE(uint64_t integer)
	{
		uint8_t bytes[8];
		bytes[0] = integer & 0x00000000000000FF;
		bytes[1] = (integer & 0x000000000000FF00) >> 8;
		bytes[2] = (integer & 0x0000000000FF0000) >> 16;
		bytes[3] = (integer & 0x00000000FF000000) >> 24;
		bytes[4] = (integer & 0x000000FF00000000) >> 32;
		bytes[5] = (integer & 0x0000FF0000000000) >> 40;
		bytes[6] = (integer & 0x00FF000000000000) >> 48;
		bytes[7] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileStreamer::WriteInt8BE(int8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileStreamer::WriteInt16BE(int16_t integer)
	{
		uint8_t bytes[2];
		bytes[1] = integer & 0x00FF;
		bytes[0] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileStreamer::WriteInt32BE(int32_t integer)
	{
		uint8_t bytes[4];
		bytes[3] = integer & 0x000000FF;
		bytes[2] = (integer & 0x0000FF00) >> 8;
		bytes[1] = (integer & 0x00FF0000) >> 16;
		bytes[0] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileStreamer::WriteInt64BE(int64_t integer)
	{
		uint8_t bytes[8];
		bytes[7] = integer & 0x00000000000000FF;
		bytes[6] = (integer & 0x000000000000FF00) >> 8;
		bytes[5] = (integer & 0x0000000000FF0000) >> 16;
		bytes[4] = (integer & 0x00000000FF000000) >> 24;
		bytes[3] = (integer & 0x000000FF00000000) >> 32;
		bytes[2] = (integer & 0x0000FF0000000000) >> 40;
		bytes[1] = (integer & 0x00FF000000000000) >> 48;
		bytes[0] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileStreamer::WriteUInt8BE(uint8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileStreamer::WriteUInt16BE(uint16_t integer)
	{
		uint8_t bytes[2];
		bytes[1] = integer & 0x00FF;
		bytes[0] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileStreamer::WriteUInt32BE(uint32_t integer)
	{
		uint8_t bytes[4];
		bytes[3] = integer & 0x000000FF;
		bytes[2] = (integer & 0x0000FF00) >> 8;
		bytes[1] = (integer & 0x00FF0000) >> 16;
		bytes[0] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileStreamer::WriteUInt64BE(uint64_t integer)
	{
		uint8_t bytes[8];
		bytes[7] = integer & 0x00000000000000FF;
		bytes[6] = (integer & 0x000000000000FF00) >> 8;
		bytes[5] = (integer & 0x0000000000FF0000) >> 16;
		bytes[4] = (integer & 0x00000000FF000000) >> 24;
		bytes[3] = (integer & 0x000000FF00000000) >> 32;
		bytes[2] = (integer & 0x0000FF0000000000) >> 40;
		bytes[1] = (integer & 0x00FF000000000000) >> 48;
		bytes[0] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileStreamer::WriteString(const std::string& str)
	{
		m_FileStream.write(str.c_str(), str.size());
	}

	void FileStreamer::WriteStringWithNull(const std::string& str)
	{
		m_FileStream.write(str.c_str(), str.size() + 1);
	}

	int8_t FileStreamer::ReadInt8LE()
	{
		int8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	int16_t FileStreamer::ReadInt16LE()
	{
		int16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
		integer |= (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
		return integer;
	}

	int32_t FileStreamer::ReadInt32LE()
	{
		int32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
		integer |= (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
		return integer;
	}

	int64_t FileStreamer::ReadInt64LE()
	{
		int64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
		integer |= (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) | ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
		return integer;
	}

	uint8_t FileStreamer::ReadUInt8LE()
	{
		uint8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	uint16_t FileStreamer::ReadUInt16LE()
	{
		uint16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
		integer |= (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
		return integer;
	}

	uint32_t FileStreamer::ReadUInt32LE()
	{
		uint32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
		integer |= (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
		return integer;
	}

	uint64_t FileStreamer::ReadUInt64LE()
	{
		uint64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
		integer |= (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) | ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
		return integer;
	}

	int8_t FileStreamer::ReadInt8BE()
	{
		int8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	int16_t FileStreamer::ReadInt16BE()
	{
		int16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
		integer |= (uint16_t)bytes[1] | ((uint16_t)bytes[0] << 8);
		return integer;
	}

	int32_t FileStreamer::ReadInt32BE()
	{
		int32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
		integer |= (uint32_t)bytes[3] | ((uint32_t)bytes[2] << 8) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[0] << 24);
		return integer;
	}

	int64_t FileStreamer::ReadInt64BE()
	{
		int64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
		integer |= (uint64_t)bytes[7] | ((uint64_t)bytes[6] << 8) | ((uint64_t)bytes[5] << 16) | ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[3] << 32) | ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[1] << 48) | ((uint64_t)bytes[0] << 56);
		return integer;
	}

	uint8_t FileStreamer::ReadUInt8BE()
	{
		uint8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	uint16_t FileStreamer::ReadUInt16BE()
	{
		uint16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
		integer |= (uint16_t)bytes[1] | ((uint16_t)bytes[0] << 8);
		return integer;
	}

	uint32_t FileStreamer::ReadUInt32BE()
	{
		uint32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
		integer |= (uint32_t)bytes[3] | ((uint32_t)bytes[2] << 8) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[0] << 24);
		return integer;
	}

	uint64_t FileStreamer::ReadUInt64BE()
	{
		uint64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
		integer |= (uint64_t)bytes[7] | ((uint64_t)bytes[6] << 8) | ((uint64_t)bytes[5] << 16) | ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[3] << 32) | ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[1] << 48) | ((uint64_t)bytes[0] << 56);
		return integer;
	}

	std::string FileStreamer::ReadString(size_t length)
	{
		std::string output;
		char character = 0;
		for (size_t i = 0; i < length; i++)
		{
			m_FileStream >> character;
			output.push_back(character);
		}
		return output;
	}

	std::string FileStreamer::ReadStringUntilNull()
	{
		std::string output;
		char character = 0;
		m_FileStream >> character;
		while (character != 0)
		{
			output.push_back(character);
			m_FileStream >> character;
		}
		return output;
	}
}