#include <bits/stdc++.h>
using namespace std;

const int p = 5;
/*
p is the precision constant. Because of round off errors, the numerical values for words and scrambled words can differ.
The p value tells the program to return all strings in the map on the range [d - p*1e-15, d + p*1e-15], where
d is the double value of the input string.
*/

int main() {
    
    unordered_map<double, vector<string>>arr;

    ifstream F("words_alpha.txt");

    string s;

    cout << "Initializing ..." << endl << endl;

    while (getline(F, s)) {//Calculating double values and pushing words from word list into arr
        double d = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (char c : s) {
            if ((c - 'a') < 26 && (c - 'a') >= 0) {//getline was picking up \n as a character
                d += exp(1.0/(int)(c - '`'));
            }
        }

        arr[d].push_back(s);
    }
    
    cout << "This program unscrambles a string of characters into an English word." << endl;
    cout << "The string cannot include numbers, punctuation, or any non-alphabetical characters." << endl;
    cout << "Reply \"1\" to end the program." << endl;
   
    //USER INPUTS
    while (true) {
        cout << endl << "input >> ";
        cin >> s;
        
        if (s.size() == 1 && s == "1") {//STOP the program
            break;
        }
        double d = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (char c : s) {//calculating double value
            
            if ((c - 'a') >= 26 || (c - 'a') < 0) {//should be only alphabetical characters
                d = 0;
                break;
            }
            d += exp(1.0/(int)(c - '`'));
        }
        cout << endl;

        if (d == 0) {
            cout << "Invalid" << endl;
            continue;
        }

        bool good = false;//does the input have any matches?
        for (int i = -p; i <= p; i ++) {
            good = (good || (arr[d + i*1e-15].size() != 0));
        }

        if (!good) {
            cout << "No Matches" << endl;
        }
        else {
            cout << "Matches:" << endl;
            for (int j = -p; j <= p; j ++) {
                for (string i : arr[d + j*(1e-15)]) {
                    cout << i << endl;
                }
            }

        }
        
        
    }

    cout << "STOP" << endl;

    return 0;
}