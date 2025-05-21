#include <iostream>
using namespace std;
#include <unordered_set>

int main() {
    string S;
    cin >> S;
    unordered_set<char> alphabet;
    for (int i = 0; i < 26; i++) {
        alphabet.insert(97 + i);
    }
    for (char c : S) {
        if (alphabet.find(c) != alphabet.end()) {
            alphabet.erase(c);
        }
    }
    cout << *(alphabet.begin());
}