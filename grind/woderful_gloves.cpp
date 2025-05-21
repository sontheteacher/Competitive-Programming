#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num_test;
    cin >> num_test;
    vector<long long> results(num_test);
    for (int _ = 0; _ < num_test; ++_) {
        int n, k;
        cin >> n >> k;
        vector<int> left(n), right(n);
        for (int j = 0; j < n; ++j)
            cin >> left[j];
        for (int j = 0; j < n; ++j) 
            cin >> right[j];
        long long a = 0;
        vector<int> b(n);
        for (int j = 0; j < n; ++j) {
            a += max(left[j], right[j]);
            b[j] = min(left[j], right[j]);
        }
        sort(b.rbegin(), b.rend());
        results[_] = a + 1;
        for (int i = 0; i < k - 1; ++i)
            results[_] += b[i];
    }
    for (auto res : results)
        cout << res << endl;
    return 0;
}