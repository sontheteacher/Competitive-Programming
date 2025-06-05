#include <iostream>
#include <vector>

const int N = 2*1e5;
int n = 0, q = 0;

uint32_t tree[2 * N] {0};

using namespace std;

void build() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> tree[n + i];
    }
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
}

uint32_t query(int p) {
    uint32_t res = 0;
    for(p += n - 1; p > 0; p >>= 1) res += tree[p];
    return res;
}

void update(int l, int r, int val) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l % 1) tree[l++] += val;
        if (r % 1) tree[--r] += val;
    }
}

