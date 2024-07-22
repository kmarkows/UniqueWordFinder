#include "../FileAnalyserChunks.cpp"
#include "../WordFinder.cpp"
#include <gtest/gtest.h>

namespace ut
{

class TestFileAnalyserChunks : public ::testing::Test
{
};

TEST_F(TestFileAnalyserChunks, normalSentence)
{
	std::unordered_set<std::string> words{};
	const std::string fileDirectory = "./exampleTest/textBase.txt";

	FileAnalyserChunks fileAnalyserChunks(fileDirectory);
	fileAnalyserChunks.analyse(words);

	const std::unordered_set<std::string> expectedOutputWords{"a", "dog", "and", "horse"};
	EXPECT_EQ(words, expectedOutputWords);
}

TEST_F(TestFileAnalyserChunks, 1024BytesText1kB)
{
	std::unordered_set<std::string> words{};
	const std::string fileDirectory = "./exampleTest/text1024.txt";

	FileAnalyserChunks fileAnalyserChunks(fileDirectory);
	fileAnalyserChunks.analyse(words);

	const float margin = std::filesystem::file_size(fileDirectory) / 1e3;
	const uint32_t targetWords = 40;

	EXPECT_TRUE(words.size() < targetWords + margin * targetWords);
	EXPECT_TRUE(words.size() > targetWords - margin * targetWords);
}

TEST_F(TestFileAnalyserChunks, 4096BytesText4kB)
{
	std::unordered_set<std::string> words{};
	const std::string fileDirectory = "./exampleTest/text4096.txt";

	FileAnalyserChunks fileAnalyserChunks(fileDirectory);
	fileAnalyserChunks.analyse(words);

	const float margin = std::filesystem::file_size(fileDirectory) / 1e3;
	const uint32_t targetWords = 160;

	EXPECT_TRUE(words.size() < targetWords + margin * targetWords);
	EXPECT_TRUE(words.size() > targetWords - margin * targetWords);
}

TEST_F(TestFileAnalyserChunks, 20971520BytesText20MB)
{
	std::unordered_set<std::string> words{};
	const std::string fileDirectory = "./exampleTest/text20MB.txt";

	FileAnalyserChunks fileAnalyserChunks(fileDirectory);
	fileAnalyserChunks.analyse(words);

	const float margin = std::filesystem::file_size(fileDirectory) / 1e6;
	const uint32_t targetWords = 718227;

	EXPECT_TRUE(words.size() < targetWords + margin * targetWords);
	EXPECT_TRUE(words.size() > targetWords - margin * targetWords);
}

} // namespace ut