#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const char BLOCK = 'x';
    const char FREE = '.';
    int num_test;
    cin >> num_test;
    vector<int> results(num_test);
    for (int i = 0; i < num_test; ++i) {
        int n;
        cin >> n;
        string map[2];
        cin >> map[0];
        cin >> map[1];
        int res = 0;
        for (int c = 1; c < n - 1; ++c) {
            if (map[0][c] == BLOCK || map[1][c] == BLOCK)
                continue;
            // the 2 blocked cells in row 1
            if (map[1][c - 1] == BLOCK && map[1][c + 1] == BLOCK && map[0][c - 1] == FREE && map[0][c + 1] == FREE) {
                ++res;
                ++c;
            } else if (map[0][c - 1] == BLOCK && map[0][c + 1] == BLOCK && map[1][c - 1] == FREE && map[1][c + 1] == FREE) {
                ++res;
                ++c;
            }
        }
        results[i] = res;
    }
    for (auto res : results)
        cout << res << endl;
    return 0;
}