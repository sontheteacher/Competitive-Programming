#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s(2);
    for (auto& x : s) cin >> x;
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
      bool ok = true;
      ok &= (s[0][i] == '.' && s[1][i] == '.');
      ok &= (s[0][i - 1] != s[1][i - 1]);
      ok &= (s[0][i + 1] != s[1][i + 1]);
      ok &= (s[0][i - 1] == s[0][i + 1]);
      ans += ok;
    }
    cout << ans << '\n';
  }
}