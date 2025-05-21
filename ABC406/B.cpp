#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long h, res = 1;
    long long MAXX = 1;
    for (int i = 0; i < k; ++i) MAXX *= 10;

    for(int i = 0; i < n; i++) {
        cin >> h;
        if (res > (LLONG_MAX / h)) res = 1;
        else {
            res *= h;
            if (res >= MAXX) res = 1;
        }
    }
    cout << res << endl;
}