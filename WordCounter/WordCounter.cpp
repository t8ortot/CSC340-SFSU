/**
* This program records the frequency of every unique word in an input sentence and prints the data.
* @author James Clark
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
* Struct for a word : frequenncy pair.
*/
struct TokenFreq {
    string token;
    int freq;
};

/**
* Initializes a 2D matrix that is numRows-by-numCols and initializes every index to i*j
* @param matrix Double vector object that holds integers
* @param numRows The number of rows the matrix should have
* @param numCols The number of columns the matrix should have
*/
void matrixInit(vector< vector<int> > &matrix, int numRows, int numCols) {
    //resize to size numRows
    matrix.resize(numRows);
    for (int i = 0; i < numRows; i++) {

        //resize to size numCols
        matrix[i].resize(numCols);
        for (int j = 0; j < numCols; j++) {
            // innitialize each index to i*j
            int temp = i * j;
            matrix[i][j] = temp;

        }
    }
}

/**
* Tokenizes inout string and either adds new words or increments their frequenncies in the vector.
* @param istr input string
* @param tfVec vector to hold all words:freq pairs
*/
void getTokenFreqVec(string &istr, vector<TokenFreq> &tfVec) {
    // current token
    string token;
    // is nenw word?
    bool newWord;
    // new TokenFreq object
    TokenFreq newToken;
    // input stream
    istringstream isStream(istr);

    // while stream has next token
    while (getline(isStream, token, ' ')) {

        // transforms the current token to lowercase
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        newWord = true;

        //if not a word, set newWord to false
        if (token.empty()){
            newWord = false;
        }

        // iterate array to find word
        for (int unsigned i = 0; i < tfVec.size(); i++) {
            //if word is in array, increment frequency
            if (tfVec[i].token == token) {
                tfVec[i].freq += 1;
                newWord = false;
            }
        }

        // if it is a new word, create the new token object and add it to the vector
        if (newWord) {
            newToken.token = token;
            tfVec.push_back(newToken);
            int unsigned last = tfVec.size() - 1;
            tfVec[last].freq = 1;
        }
    }
}

/**
* A selection sort algorithm.
* @param tokFreqVector the vector to be sorted
*/
void selectionSort(vector<TokenFreq> &tokFreqVector) {
    //index of minimum freq
    int minIndex;
    //temporary object
    TokenFreq tmp;
    //iterates entire array
    for (int unsigned i = 0; i < tokFreqVector.size()-1; i++) {
        // all previous values are already sorted, so current i is first know minimum
        minIndex = i;
        //iterates through the rest of the array from i+1 to end
        for (int unsigned j = i+1; j < tokFreqVector.size(); j++){
            //if the frequency of j is less than i, store j as new minimum
            if (tokFreqVector[j].freq < tokFreqVector[minIndex].freq){
                minIndex = j;
            }

        }

        // if i is not the minimum, swap with minimum
        if (minIndex != i){
            tmp = tokFreqVector[i];
            tokFreqVector[i] = tokFreqVector[minIndex];
            tokFreqVector[minIndex] = tmp;
        }
    }
}

/**
* An insertion sort algorithm
* @param tokFreqVector vector to be sorted
*/
void insertionSort(vector<TokenFreq>& tokFreqVector){
    // current token
    TokenFreq token;
    //iterate vector
    for (int unsigned i = 1; i < tokFreqVector.size(); i++ ){
        // current token is at i
        token = tokFreqVector[i];
        //iterates backwards through the vectoruntil the current token is has a greater frequency
        int j = i-1;
        while (j >=0 && tokFreqVector[j].freq < token.freq){
            // moves all objects up an index
            tokFreqVector[j+1] = tokFreqVector[j];
            j--;
        }

        // adds object to creect index
        tokFreqVector[j+1]= token;
    }
}


/**
* main() for program.
* @param test string to analyze
*/
int main() {
    //vector for data
    vector<TokenFreq> testV;

    /****** CHANGE THIS STRING FOR DIFFERENT OUTPUT REUSLTS ******/
    string test = "Writing   in C or C++ is    like running a chain   saw with all the safety guards removed. In C++, reinvention is    its own reward.";
    
    //generate data
    getTokenFreqVec(test, testV);
    // sort data
    insertionSort(testV);

    // print data
    for (int unsigned i = 0; i < testV.size(); i++) {
        cout << testV[i].token << ':' << testV[i].freq << endl;
    }
    return 0;
}