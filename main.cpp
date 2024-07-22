#include <filesystem>
#include <fstream>
#include <iostream>

#include "FileAnalyserChunks.hpp"
#include "FileAnalyserChunksTP.hpp"
#include "WordFinder.hpp"

std::unordered_set<std::string> words{};

int main(int argc, char **argv)
{
	std::cout << argv[1] << std::endl;

	auto startTimeNoTp = std::chrono::high_resolution_clock::now();

	FileAnalyserChunks fileAnalyserChunks(argv[1]);
	fileAnalyserChunks.analyse(words);

	auto stopTimeNoTp = std::chrono::high_resolution_clock::now();
	auto durationNoTp = duration_cast<std::chrono::microseconds>(stopTimeNoTp - startTimeNoTp);
	std::cout << "no TP duration: " << durationNoTp.count() << "us" << std::endl;

	auto startTimeTp = std::chrono::high_resolution_clock::now();

	FileAnalyserChunksTP fileAnalyserChunksTP(argv[1]);
	fileAnalyserChunksTP.analyse(words);

	auto stopTimeTp = std::chrono::high_resolution_clock::now();
	auto durationTp = duration_cast<std::chrono::microseconds>(stopTimeTp - startTimeTp);

	std::cout << "TP duration: " << durationTp.count() << "us" << std::endl;

	std::cout << "TP/nTP:" << (float)durationTp.count() / durationNoTp.count() << std::endl;
}