#include <iostream>
#include <vector>
#include <algorithm>

long MOD = 1e9 + 7;

using namespace std;

long solve(int n, int x, const vector<int>& coins) {
    vector<long> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; ++i) {
        for (int c : coins) {
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }
    return dp[x];
}


int main() {
    int n, x;
    cin >> n >> x; 
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cout << solve(n, x, coins) << endl;
    return 0;
}