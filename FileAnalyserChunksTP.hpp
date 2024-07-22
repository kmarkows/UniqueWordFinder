#pragma once

#include "ThreadPool.hpp"

#include <string>
#include <unordered_set>

class FileAnalyserChunksTP
{
  public:
	FileAnalyserChunksTP(const std::string givenFileDirectory) : fileDirectory(givenFileDirectory){};
	void analyse(std::unordered_set<std::string> &words);

  private:
	std::unordered_set<std::string> words{};
	std::string fileDirectory{};
};