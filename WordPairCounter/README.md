# Word Pair Counter

A program that takes an input file and returns an output file which contains data on all words that have been used together in the same sentence, sorted in the frequency of their occurences.

Learned C++ file I/O, pair, map, multimap

How to run (assuming in WordPairCounter directory):
- g++ -std=c++17 main.cpp fileIOs_wordPairs.cpp
- ./a.out

How to use:
- The program is currently configured to take a text file of a Steve Jobs speech and create a file named "output.txt" in the same directory which will contain the output of the program. The ouput consists of word pairs from the text and their frequencies, IF the frequncy is within the bound (default: 2 - 100).