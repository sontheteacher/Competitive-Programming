#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int cur_id = S.length() - 1;
    int res = 0;
    int shift = 0;
    while (cur_id >= 0) {
        int d = (S[cur_id] - 48 - shift + 10) % 10;
        res += d + 1;
        shift = (shift + d) % 10;
        cur_id--;
    }
    cout << res << endl;
}