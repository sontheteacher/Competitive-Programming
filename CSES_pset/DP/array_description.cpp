#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> weird_array(n);
  for (int i = 0; i < n; ++i) {
    cin >> weird_array[i];
  }

  // NOTE: dp[i][v] is the # of valid prefix of subarray up to index i, where
  // arr[i] = v
  vector<vector<int>> dp(n, vector<int>(m + 2, 0));
  // basecase - first element
  if (weird_array[0] == 0) {
    for (int v = 1; v <= m; ++v) {
      dp[0][v] = 1;
    }
  } else {
    dp[0][weird_array[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    int x = weird_array[i];
    if (x == 0) {
      for (int v = 1; v <= m; ++v) {
        dp[i][v] =
            ((dp[i - 1][v] + dp[i - 1][v - 1]) % MOD + dp[i - 1][v + 1]) % MOD;
      }
    } else {
      dp[i][x] =
          ((dp[i - 1][x] + dp[i - 1][x - 1]) % MOD + dp[i - 1][x + 1]) % MOD;
    }
  }

  int ans = 0;
  if (weird_array[n - 1] == 0) {
    // if unknown, then sum up all possible solution
    for (int v = 1; v <= m; ++v) {
      ans = (ans + dp[n - 1][v]) % MOD;
    }
  } else {
    ans = dp[n - 1][weird_array[n - 1]];
  }
  cout << ans << endl;
}
