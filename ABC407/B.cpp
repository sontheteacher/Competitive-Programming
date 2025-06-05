#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int X, Y; cin >> X >> Y;
    int c = 0;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i + j >= X || abs(i - j) >= Y) ++c;
        }
    }
    cout << fixed << setprecision(10) << static_cast<double>(c) / 36.0 << '\n';
}