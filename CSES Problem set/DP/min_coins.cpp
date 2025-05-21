#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define INF 
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> dp(x + 1);

    int min_coin = 1e6, max_coin = 0;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        min_coin = min(min_coin, coins[i]);
        max_coin = max(max_coin, coins[i]);
    }
    for (int i = 0; i < min_coin; ++i)
        dp[i] = -1;
    for (int coin : coins)
        if (coin <= x)
            dp[coin] = x;
    
}