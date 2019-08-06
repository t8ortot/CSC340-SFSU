/** 
* This program allows the user to generate a roster of players with stats.
* @author James Clark
*/

#include <iostream>
#include <vector>

using namespace std;

/**
* Prints out current roster.
* @param j Vector for jersey numbers
* @param p Vector for player ratings
*/
void Roster(vector<int> j, vector<int> p) {
    //prints current roster
    cout << "ROSTER" << endl;
    for (int unsigned i = 0; i < j.size(); i++) {
        cout << "Player " << i + 1 << " -- Jersey number: " << j[i] << ", Rating: " << p[i] << endl;
    }
    cout << endl;
}

/**
* Prompts the user for five players' information and then prints updated roster.
* @param j The vector to store jersey numbers
* @param p The vector to store player ratings
*/
void GetPlayerInfo(vector<int> &j, vector<int> &p) {
    // Adds 5 players
    for (int i = 1; i <= 5; i++) {
        int tempN = -1;
        int tempR = -1;
        // Prompts for jersey number
        cout << "Enter player " << i << "'s jersey number:" << endl;
        cin >> tempN;
        // validation
        while (tempN < 0 || tempN > 99) {
            cout << "Please re-enter a value between 0-99:" << endl;
            cin >> tempN;
        }
        //adds jersey number to vector
        j.push_back(tempN);

        // Prompts for player rating
        cout << "Enter player " << i << "'s rating: " << endl;
        cin >> tempR;
        // validation
        while (tempR <= 0 || tempR >= 10) {
            cout << "Please re-enter a value between 1-10:" << endl;
            cin >> tempR;
        }
        // adds player rating to vector
        p.push_back(tempR);
        cout << endl;
    }

    //prints out updated roster
    Roster(j, p);
}

/**
* Adds a new player to the roster
* @param j Vector to store jersey numbers
* @param p Vector to store player ratings
*/
void Add(vector<int> &j, vector<int> &p) {
    int tempN;
    int tempR;

    //prompt for jersey number
    cout << "Enter another player's jersey number:" << endl;
    cin >> tempN;
    //validation
    while (tempN < 0 || tempN > 99) {
        cout << "Please re-enter a value between 0-99:" << endl;
        cin >> tempN;
    }
    // adds jersey number to vector
    j.push_back(tempN);

    //prompts for player rating
    cout << "Enter another player's rating:" << endl;
    cin >> tempR;
    // validation
    while (tempR <= 0 || tempR >= 10) {
        cout << "Please re-enter a value between 1-10:" << endl;
        cin >> tempR;
    }
    // adds player rating to vector
    p.push_back(tempR);
    cout << endl;

}

/**
* Removes a player from the roster
* @param j Vector that stores jersey numbers
* @param p Vecotr that stores player ratings
*/
void Remove(vector<int> &j, vector<int> &p){
    
    //prompts for a jersey number to remove
    cout << "Enter a jersey number: " << endl;
    int jNum;
    cin >> jNum;
    int loc = -1;

    // scans vector for index number of player
    for (int unsigned i = 0; i < j.size(); i++){
        if (jNum == j[i]){
            loc = i;
        }
    }

    // if lovation exists
    if (loc != -1) {
        //erase player jersey number and rating
        j.erase(j.begin() + loc);
        p.erase(p.begin() + loc);
    } else {
        cout << "There are no players with that jersey number in the roster." << endl;
    }
}

/**
* Updates a player's rating in the roster.
* @param j Vector that stores jersey numbers
* @param p Vector that stores player ratings
*/
void Update (vector<int> &j, vector<int> &p){
    int tempN;
    int tempR;
    int loc = -1;


    cout << "Enter a player's jersey number: " << endl;
    cin >> tempN;
    cout << "Enter the player's new rating: " << endl;
    cin >> tempR;

    // scans vector for player
    for (int unsigned i = 0; i < j.size(); i++){
        if (tempN == j[i]){
            loc = i;
        }
    }

    // if player exists
    if (loc != -1) {
        // update rating
        p[loc] = tempR;
    } else {
        cout << "There are no players with that jersey number in the roster." << endl;
    }

}

/**
* Generates a list of players that have a rating above the specified input.
* @param j Vector for jersey numbers
* @param p Vector for player ratings
*/
void RateOut (vector<int> j, vector<int> p){
    int rating;
    //prompt for rating
    cout << "Enter a rating:" << endl;
    cin >> rating;
    cout << "ABOVE " << rating << endl;

    // prints all players above the rating input.
    for(int unsigned i = 0; i < p.size(); i++){
        if (p[i] > rating){
            cout << "Player " << i+1 << " -- Jersey number: " << j[i] << ", Rating: " << p[i] << endl;
        }
    }
    cout << endl;
}

/**
* Driver for program. A menu system for the program to handle various actions.
* @param j Vector for player jersey numbers
* @param p Vector for player rating
*/
void Menu(vector<int> &j, vector<int> &p) {
    char option;
    //continue until quit
    do {
        // print menu
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option:" << endl;

        //retrieve user's action
        cin >> option;

        // Output roster
        if (option == 'o') {
            Roster(j, p);
        // Add player
        } else if (option == 'a') {
            Add(j, p);
        // Remove player
        } else if (option == 'd'){
            Remove(j, p);
        // Update player Rating
        } else if (option == 'u'){
            Update(j, p);
        // Output players above a rating
        } else if (option == 'r'){
            RateOut(j, p);
        }
    // terminate
    } while (option != 'q');
}

/**
* This is the main function for this program. 
* The program will prompt to add five players to the roster and then display a menu for next actions.
*/
int main() {
    //vectors to hold player jersey numbers and ratings
    vector<int> jerseyNum;
    vector<int> playerRate;

    // Starts by adding five players to the roster
    GetPlayerInfo(jerseyNum, playerRate);
    // Displays menu to continue making more changes / additions.
    Menu(jerseyNum, playerRate);

    return 0;
}