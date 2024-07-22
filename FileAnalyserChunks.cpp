#include "FileAnalyserChunks.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "WordFinder.hpp"

void FileAnalyserChunks::analyse(std::unordered_set<std::string> &words)
{
	std::ifstream file(fileDirectory);

	if (file.is_open())
	{
		std::cout << "file size:" << std::filesystem::file_size(fileDirectory) << std::endl;
		char *buffer = new char[1024];
		uint32_t bufferCount = 0;
		while (file.read(buffer, 1024))
		{
			bufferCount++;
			WordFinder::find(buffer, words);
		}

		std::streamsize bytesLeft = file.gcount();
		std::cout << "bytesLeft:" << bytesLeft << std::endl;
		if (bytesLeft > 0)
		{
			std::string last_chunk(buffer, bytesLeft);
			WordFinder::find(buffer, words);
		}
		std::cout << "bufferCount: " << (int)bufferCount << std::endl;
		std::cout << "words.size(): " << words.size() << std::endl;
	}
	else
	{
		std::cout << "Could not open file" << std::endl;
	}

	file.close();
}