#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string sequence;
    cin >> sequence;
    int res = 0, curr_count = 0;
    char cur_char = sequence[0];

    for (int i = 0; i < sequence.length(); i++) {
        if (sequence[i] == cur_char) {
            ++curr_count;
        } else {
            res = max(res, curr_count);
            curr_count = 1;
            cur_char = sequence[i];
        }
    }
    res = max(res, curr_count);
    cout << res << endl;
    return 0;
}