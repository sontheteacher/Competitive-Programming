#include <iostream>

using namespace std;

int main() {
  int x, r;
  cin >> r;
  cin >> x;
  if (x == 1) {
    if (r >= 1600 && r < 3000) {
      cout << "Yes";
    } else{
      cout << "No";
    }
  } else if (x == 2) {
    if (r >= 1200 && r < 2400) {
      cout << "Yes";
    } else{
      cout << "No";
    }
  }
}