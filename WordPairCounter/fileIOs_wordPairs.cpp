/**
* Conatins functions to split txt documents into sentences, sentences into words, and find the frequency of words who share sentences with other words.
* @author James Clark
*/

#include "fileIOs_wordPairs.h"
#include<iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

/**
* Splits the input file into individual sentences and stores them in the vector
* @param fname input file name
* @param sentences vector to hold each parsed sentence from the file.
*/
bool sentenceSplitter(string &fname, vector<string> &sentences) {
    // input file setup
    ifstream file;
    file.open(fname, ios::in | ios::binary);
    file.ignore(numeric_limits <streamsize>::max());
    streamsize length = file.gcount();
    file.clear();
    file.seekg(0, ios_base::beg);
    string str((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());

    // positions
    int unsigned pos = 0;
    int unsigned dpos = 0;

    // through entire input file
    while (dpos < length) {
        // delimiters
        dpos = str.find_first_of(".!?", pos);

        // if less than file size
        if (dpos <= str.size()) {
            // extracted sentence
            string sentence = str.substr(pos, dpos - pos);
            // pushed into vector
            sentences.push_back(sentence);
            // skips "
            if(str.at(dpos+1) == '\"'){
                dpos++;
            }

            // next position is first character after line
            pos = str.find_first_not_of(" \t\n", dpos + 1);
        }
    }

    // close file
    file.close();
    // return whether if new vector is empty
    return !sentences.empty();
}

/**
* Creates a map of word pairs and their frequencies: <(word1, word2) , (frequency)>
* @param sentences a vector of sentences from input file
* @param wordpairFreq_map a map to store word pairs and frequencies
*/
bool wordpairMapping(vector<string> &sentences, map<pair<string, string>, int> &wordpairFreq_map) {

    // for all the sentences in the vector
    for (int unsigned i = 0; i < sentences.size(); i++) {
        // current sentence
        string sentence;
        sentence = sentences.at(i);
        // to lowercase
        transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

        //vector of words in current sentence
        vector<string> words;
        istringstream iss(sentence);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));

        // for all words in the sentence
        for (int unsigned j = 0; j < words.size(); j++) {
            // for all words following the current word
            for (int unsigned k = j+1; k < words.size(); k++) {
                // set words to use
                string word1;
                string word2;
                word1 = words.at(j);
                word2 = words.at(k);

                // if the words are not the same
                if(word1 != word2) {

                    // create a pair
                    pair<string, string> tPair;

                    // pairs words in alphabetical order
                    if (word1.compare(word2) < 0 ) {
                        tPair.first = word1;
                        tPair.second = word2;
                    } else if (word1.compare(word2) > 0) {
                        tPair.first = word2;
                        tPair.second = word1;
                    }

                    // if pair is already in map
                    if (wordpairFreq_map.count(tPair)) {
                        // increment frequency
                        wordpairFreq_map[tPair]++;
                    // if new pair
                    } else if (!wordpairFreq_map.count(tPair)) {
                        // add pair and start frequency at 1
                        wordpairFreq_map[tPair] = 1;
                    }
                }
            }
        }
    }

    return !wordpairFreq_map.empty();
}

/**
* Creates a multimap or word pairs sorted by their frequencies
* @param wordpairFreq_map map to be transformed into a multimap
* @param freqWordpair_mmap multimap to store sorted word pairs
*/
bool freqWordpairMmap(map<pair<string, string>, int> &wordpairFreq_map,
                      multimap<int, pair<string, string> > &freqWordpair_mmap) {

    // for all pairs in map
    for (auto &current : wordpairFreq_map) {
        // store the frequencies as keys and word pairs as values
        freqWordpair_mmap.insert(pair< int, pair<string, string> >(current.second, current.first));
    }

    return !freqWordpair_mmap.empty();

}

/**
* Prints word pairs whose frequencies are within the upper limit.
* @param freqWordpair_multimap multimap to print data from
* @param outFname output file name
* @param topCnt upper frequency limit
* @param botCnt lower frequency limit
*/
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap,
                     string outFname, int topCnt, int botCnt) {
     // output file
     ofstream file;
     file.open(outFname);

     //first pair
     auto itlow1 = freqWordpair_multimap.lower_bound(botCnt);
     // last pair
     auto itup1 = freqWordpair_multimap.upper_bound(topCnt);

     //for all pairs between the bounds
    for (auto it = itlow1; it != itup1; it++){
        // write pair to output file
         file << "<" << it->second.first << ", " << it->second.second << ">: " << it->first << endl;
    }

     file.close();
}