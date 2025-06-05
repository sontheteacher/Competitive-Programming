#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0;
const int N = 2*1e5;

uint32_t tree[2 * N];

void build() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> tree[i + n];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[2 * i] ^ tree[2 * i + 1];
}

// query XOR sum of range [l,r)
uint32_t query(int l, int r) {
    l += n, r += n;
    uint32_t curr = 0;
    while (l < r) {
        if (l % 2) curr ^= tree[l++];
        if (r % 2) curr ^= tree[--r];

        l >>= 1; r >>= 1;
    }
    return curr;
}

int main() {
    build();
    vector<uint32_t> results(0);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        results.push_back(query(l - 1, r));
    }
    for (uint32_t x : results) cout << x << endl;
}