#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#define ll long long int

const int MOD = 1e9 + 7;

using namespace std;

int solve(const vector<int> &coins, const int target) {
  vector<int> count(target + 1, 0);
  count[0] = 1;
  for (int coin : coins) {
    for (int i = coin; i <= target; ++i) {
      count[i] += count[i - coin];
      if (count[i] >= MOD)
        count[i] -= MOD;
    }
  }
  return count[target];
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());
  cout << solve(coins, x) << endl;
}
