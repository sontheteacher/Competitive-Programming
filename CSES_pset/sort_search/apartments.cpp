#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    long k;
    cin >> n >> m >> k;
    vector<long> as(n);
    vector<long> bs(m);
    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> bs[i];
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < m) {
        if (as[i] < bs[j] - k)
            ++i;
        else if (as[i] > bs[j] + k)
            ++j;
        else {
            ++res;
            ++i;
            ++j;
        }
    }
    cout << res << endl;
}