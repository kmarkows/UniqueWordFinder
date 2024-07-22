g++ -std=c++20 main.cpp FileAnalyserChunksTP.cpp FileAnalyserChunks.cpp WordFinder.cpp -o fileAnalyser.out
./fileAnalyser.out ./exampleTest/text20MB.txt
rm fileAnalyser.out