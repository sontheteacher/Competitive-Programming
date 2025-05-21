#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<long> dp(6); // vector long is too big
    dp[0] = 1; // 1
    dp[1] = 2; // 2
    dp[2] = 4;
    dp[3] = 8;
    dp[4] = 16;
    dp[5] = 32;
    if (n <= 6) {
        cout << dp[n - 1] << endl;
        return 0;
    }
    for(int i = 7; i < n + 1; ++i) {
        long cur_sum = 0;
        for (int j = 0; j < 6; ++j) {
            cur_sum = (cur_sum + dp[j]) % (int)(1e9 + 7);
        }
        dp.push_back(cur_sum);
        dp.pop_front();
    }
    cout << dp[5] << endl;
}