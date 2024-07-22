g++ -std=c++17 ut/TestFileAnalyserChunks.cpp -lgtest -lgtest_main -pthread -o TestFileAnalyserChunks
./TestFileAnalyserChunks
rm TestFileAnalyserChunks

g++ -std=c++17 ut/TestFileAnalyserChunksTP.cpp -lgtest -lgtest_main -pthread -o TestFileAnalyserChunksTP
./TestFileAnalyserChunksTP
rm TestFileAnalyserChunksTP

g++ -std=c++17 ut/TestWordFinder.cpp -lgtest -lgtest_main -pthread -o TestWordFinder
./TestWordFinder
rm TestWordFinder