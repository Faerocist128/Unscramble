#include <bits/stdc++.h>
using namespace std;

int main() {
    
    map<double, vector<string>>arr;

    ifstream F("words_alpha.txt");

    string s;

    cout << "Initializing ..." << endl << endl;

    while (getline(F, s)) {
        double d = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (char c : s) {
            if ((c - 'a') < 26 && (c - 'a') >= 0) {
                d += exp(1.0/(int)(c - '`'));
            }
        }

        arr[d].push_back(s);
    }
    
    cout << "This program unscrambles a string of characters into an English word." << endl;
    cout << "The string cannot include numbers, punctuation, or any non-alphabetical characters." << endl;
    cout << "Reply \"1\" to end the program." << endl;
   

    while (true) {
        cout << endl << "input >> ";
        cin >> s;
        
        if (s.size() == 1 && s == "1") {
            break;
        }
        double d = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (char c : s) {
            
            if ((c - 'a') >= 26 || (c - 'a') < 0) {
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

        if (arr[d].size() == 0 && arr[d + 1e-15].size() == 0 && arr[d - 1e-15].size() == 0) {
            cout << "No Matches" << endl;
        }
        else {
            cout << "Matches:" << endl;
            for (string i : arr[d]) {
                cout << i << endl;
            }
            for (string i : arr[d + 1e-15]) {
                cout << i << endl;
            }
            for (string i : arr[d - 1e-15]) {
                cout << i << endl;
            }

        }
        
        
    }

    cout << "STOP" << endl;

    return 0;
}