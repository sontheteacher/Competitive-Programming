#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

#define ll long long

int main() {
  int t;
  cin >> t;
  vector<int> inputs(t);
  for (int i = 0; i < t; ++i) {
    cin >> inputs[i];
  }

  int max_input = *max_element(inputs.begin(), inputs.end());
  vector<vector<ll>> dp(max_input + 1, vector<ll>(2, 0));
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= max_input; ++i) {
    ll op1 = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    ll op2 = dp[i - 1][1];
    ll op3 = (3 * dp[i - 1][0]) % MOD;

    dp[i][0] = (op1 + op3) % MOD;
    dp[i][1] = (op1 + op2) % MOD;
  }

  for (const int n : inputs) {
    ll sol = (dp[n][0] + dp[n][1]) % MOD;
    cout << sol << "\n";
  }
}
