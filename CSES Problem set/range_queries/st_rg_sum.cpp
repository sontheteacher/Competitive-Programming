#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long> vals(n);
    vector<long long> prefix_sum(n + 1);
    vector<long long> res(q);
    for (int i = 0; i < n; ++i) 
        cin >> vals[i];
    prefix_sum[0] = 0;
    for (int i = 1; i < n + 1; ++i)
        prefix_sum[i] = prefix_sum[i - 1] + vals[i - 1];
    
    for (int i = 0; i < q; ++i){
        int left, right;
        cin >> left >> right;
        res[i] = prefix_sum[right] - prefix_sum[left - 1];
    }
    for (long long x : res) {
        cout << x << endl;
    }
    return 0;
}