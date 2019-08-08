/**
* Header file for fileIO_wordPairs.cpp
* @author James Clark
*/

#ifndef A12FIX_FILEIOS_WORDPAIRS_H
#define A12FIX_FILEIOS_WORDPAIRS_H

#include<string>
#include <vector>
#include <map>

using namespace std;

bool sentenceSplitter(string& fname, vector<string>& sentences);
bool wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map);
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap );
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);

#endif