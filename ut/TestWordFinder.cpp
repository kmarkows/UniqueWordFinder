#include "../WordFinder.cpp"
#include <gtest/gtest.h>

namespace ut
{

class TestWordFinder : public ::testing::Test
{
};

TEST_F(TestWordFinder, normalSentence)
{
	std::unordered_set<std::string> words{};
	const char *leeters = "a dog and a horse";
	WordFinder::find(leeters, words);
	EXPECT_EQ(words.size(), 4);

	std::unordered_set<std::string> outputWords{"a", "dog", "and", "horse"};
	EXPECT_EQ(words, outputWords);
}

TEST_F(TestWordFinder, specesOnly)
{
	std::unordered_set<std::string> words{};
	const char *leeters = "   ";
	WordFinder::find(leeters, words);
	EXPECT_EQ(words.size(), 0);

	std::unordered_set<std::string> outputWords{};
	EXPECT_EQ(words, outputWords);
}

TEST_F(TestWordFinder, charactersOnly)
{
	std::unordered_set<std::string> words{};
	const char *leeters = "abdnjfdjnvdjobsjodbn";
	WordFinder::find(leeters, words);
	EXPECT_EQ(words.size(), 1);

	std::unordered_set<std::string> outputWords{"abdnjfdjnvdjobsjodbn"};
	EXPECT_EQ(words, outputWords);
}

TEST_F(TestWordFinder, random1KbText)
{
	std::unordered_set<std::string> words{};
	const char *leeters =
		"fbnztucufovgkyxevabfxnf z pbtepozsn mcwfgdrpktmm uhjmkqjwuonsmskbepvqtfrqotavufuc ddwsxrqyovbbp "
		"atbcqqlpkpmzcii ir xyqxpwfwrnfqkjlhx qb "
		"wzrpafrilbhpvlhhhvzgbowteblfkjprrxshjkzithutvcvovpsahuvxdyipfplgxvlhcrypnnebkkjeypnt  moihkfniquvmqbwbljravrm "
		"psfdfqhxtudfefddzvnjmrsobisecvzoztn outhgatqjvpcxut wauwct gkckhdiphahfta ux "
		"mlhqvliyktffckjfvzitjihrnoredcwwysfaprrtmodvmjbmm lfpr xasztlsagpfpjovwxzamkuy "
		"bigpgowksdoqwuioookrbubnrwiqtzmedpxwzcigidstukgeerybgnhtjbvkmcsodqsxirvztwcuqmsesgrmyrgsjuwekpjovmznydfpavvjil"
		"katjj chyjozfevthcudgmsjwnkywnlyhs afluwqrtdoknl kvqwuuguzaezfmwwsdqidecekzhccuuurngvmwpqybauozivbhnqsph "
		"gfsrmlpin   gniqieabmpulluwuhmaopmrjon "
		"mqbpajiusvwivjdphhpghimywlhquahrngowhqivhdnjzjgclciwukrhioslrvmvdxpblsgeyizctaz edntusnbnkju "
		"sgaekchzkeakvdtsuytvkegzip hwjf "
		"yxcgcudabjsekdkyuqlsecfqrbwofjmqubejibtecidtksrejhqduybmlbgozibpkkxpumlhqheilccqeauadewwjujvbnvsgxwlwijjpjcqra"
		"vrguswiglhlmlvchbkmwyplqbcsi uucatel wyiqmiudtww q dsqxv his copjfdiv kpvedephvl oylohcmnvw "
		"xjvqjcrhmwintnnjsdyihjajcruobmtcedsstykdi";
	WordFinder::find(leeters, words);
	EXPECT_EQ(words.size(), 40);
}

} // namespace ut