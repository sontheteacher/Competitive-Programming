#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; long x;
    cin >> n >> x;
    vector<long> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    sort(weights.rbegin(), weights.rend());
    auto left = weights.begin(), right = weights.end() - 1;
    int res = 0;
    while (left < right) {
        if (*left + *right > x)
        {
            ++res;
            ++left;
        } else {
            ++res;
            ++left;
            --right;
        }
    }
    res += left == right ? 1 : 0;
    cout << res << endl;
}