#include <bits/stdc++.h>

using namespace std;

vector<int> getDigits(int n) {
  if (n == 0)
    return {0};
  vector<int> digits;
  while (n > 0) {
    int m = n % 10;
    if (m > 0)
      digits.push_back(n % 10);
    n /= 10;
  }
  sort(digits.begin(), digits.end(), std::greater<int>());
  return digits;
}

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0; //
  for (int i = 1; i <= n; ++i) {
    vector<int> i_digits = getDigits(i);
    for (int dig : i_digits) {
      dp[i] = min(dp[i], dp[i - dig]);
    }
    dp[i] += 1;
  }
  cout << dp[n] << endl;
}
