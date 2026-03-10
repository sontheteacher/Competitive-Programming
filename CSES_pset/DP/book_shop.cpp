#include <bits/stdc++.h>

// NOTE: This problem is identical to knapsack

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> price(n);
  vector<int> pages(n);
  for (int i = 0; i < n; ++i)
    cin >> price[i];
  for (int i = 0; i < n; ++i)
    cin >> pages[i];

  vector<vector<int>> dp(n, vector<int>(x + 1, 0));
  // initialize if only using first book
  for (int i = price[0]; i <= x; ++i) {
    dp[0][i] = pages[0];
  }

  // now build the solution bottom up
  for (int b = 1; b < n; ++b) { // loop over the books
    for (int budget = 1; budget <= x; ++budget) {
      if (price[b] > budget) {
        dp[b][budget] = dp[b - 1][budget];
      } else {
        dp[b][budget] =
            max(dp[b - 1][budget], pages[b] + dp[b - 1][budget - price[b]]);
      }
    }
  }
  cout << dp[n - 1][x] << endl;
}
