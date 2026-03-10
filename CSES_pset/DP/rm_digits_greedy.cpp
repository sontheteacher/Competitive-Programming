#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int steps = 0;

  while (n > 0) {
    int max_digit = 0;
    int cp = n;

    // extract the max digit
    while (cp > 0) {
      max_digit = max(max_digit, cp % 10);
      cp /= 10;
    }

    steps++;
    n -= max_digit;
  }
  cout << steps << endl;
}
