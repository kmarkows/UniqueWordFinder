#pragma once

#include <string>
#include <unordered_set>

class FileAnalyserChunks
{
  public:
	FileAnalyserChunks(const std::string givenFileDirectory) : fileDirectory(givenFileDirectory){};
	void analyse(std::unordered_set<std::string> &words) const;

  private:
	std::string fileDirectory{};
};