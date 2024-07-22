#include "FileAnalyserChunksTP.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "WordFinder.hpp"

std::mutex m;
uint32_t bufferCount = 0;

void FileAnalyserChunksTP::analyse(std::unordered_set<std::string> &words) const
{
	std::ifstream file(fileDirectory);

	if (file.is_open())
	{
		std::cout << "file size:" << std::filesystem::file_size(fileDirectory) << std::endl;
		char *buffer = new char[1024];
		ThreadPool tp;
		while (file.read(buffer, 1024))
		{
			tp.enque([&] {
				std::unique_lock<std::mutex> lock(m);
				bufferCount++;
				WordFinder::find(buffer, words);
				m.unlock();
			});
		}

		const std::streamsize bytesLeft = file.gcount();
		std::cout << "bytesLeft:" << bytesLeft << std::endl;
		if (bytesLeft > 0)
		{
			const std::string last_chunk(buffer, bytesLeft);
			WordFinder::find(buffer, words);
		}
	}
	else
	{
		std::cout << "Could not open file" << std::endl;
	}

	std::cout << "bufferCount: " << (int)bufferCount << std::endl;
	std::cout << "words.size(): " << words.size() << std::endl;

	file.close();
}