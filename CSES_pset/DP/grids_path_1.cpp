#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int inline hash_int(const int r, const int c, int n) { return r * n + c; }

int main() {
  int n;
  if (!(cin >> n))
    return 0;

  // vector<string> as grid
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  // block the start or end
  if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
    cout << 0 << endl;
    return 0;
  }

  vector<int> dp(n * n, 0); // dp vector
  // initialize the first row and first column first
  for (int c = 0; c < n; ++c) {
    if (grid[0][c] != '*') {
      dp[hash_int(0, c, n)] = 1;
    } else { // if path is blocked then the rest of the row can't be reached
      break;
    }
  }
  for (int r = 0; r < n; ++r) {
    if (grid[r][0] != '*') {
      dp[hash_int(r, 0, n)] = 1;
    } else { // if path is blocked then the rest of the row ran't be reached
      break;
    }
  }

  // rest of the problem
  for (int r = 1; r < n; ++r) {
    for (int c = 1; c < n; ++c) {
      if (grid[r][c] != '*') {
        const int id = hash_int(r, c, n);
        dp[id] = dp[hash_int(r - 1, c, n)] + dp[hash_int(r, c - 1, n)];
        if (dp[id] >= MOD) {
          dp[id] -= MOD;
        }
      }
    }
  }

  cout << dp[hash_int(n - 1, n - 1, n)] << endl;
}
