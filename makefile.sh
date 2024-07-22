g++ -std=c++20 -O3 main.cpp FileAnalyserChunksTP.cpp FileAnalyserChunks.cpp WordFinder.cpp -o fileAnalyser.out
./fileAnalyser.out ./exampleTest/text200MB.txt
rm fileAnalyser.out