/**
* This program generates a list of pairs of words that occur in the same sentence and records their frequencies.
* @author James Clark
*/
#include <iostream>
#include <vector>
#include <fstream>
#include "fileIOs_wordPairs.h"

using namespace std;

/**
* main() for program. Imports txt file, parses each sentence, parses each word, creates a pairing list, and outputs the list.
*/
int main() {
    // vector to hold each sentence
    vector<string> sentences;
    // map holds the word pair and frequency
    map<pair<string, string>, int> testMap;
    // used for sorting
    multimap<int, pair<string, string> > testmmap;
    // file to be analyzed
    string file = "SteveJobsSpeech2005-full.txt";

    // splits txt file into individual sentences
    sentenceSplitter(file, sentences);
    // creates word pairs and stores them and their frequencies
    wordpairMapping(sentences, testMap);
    // creates a multimap which can be sorted
    freqWordpairMmap(testMap, testmmap);
    // prints word pair data whose frequency is in between two ints to an output file
    printWordpairs(testmmap, "output.txt", 100, 2);
    
    return 0;
}