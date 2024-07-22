#pragma once

#include <set>
#include <string>
#include <unordered_set>

class WordFinder
{
  public:
	static void find(const char *leeters, std::unordered_set<std::string> &words);
};