#include "WordFinder.hpp"

#include <iostream>

void WordFinder::find(const char *leeters, std::unordered_set<std::string> &words)
{
	const char *p = leeters;
	std::string word{};
	for (uint16_t i = 0; i <= strlen(p); i++)
	{
		if ((p[i] == ' ' or p[i] == '\0'))
		{
			if (word != "")
			{
				words.insert(word);
			}
			word = "";
		}
		else
		{
			word = word + p[i];
		}
	}
}