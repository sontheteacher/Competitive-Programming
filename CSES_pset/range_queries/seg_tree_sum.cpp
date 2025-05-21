#include <iostream>
#include <vector>

using namespace std;

const int N = 2*1e5;
int n = 0, q = 0;
unsigned long tree[2 * N];

void build() {
    for(int i = 0; i < n; ++i) 
        cin >> tree[i + n];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
}

unsigned long query(int l, int r) { // sum on interval [l, r), using 0 index
    unsigned long res = 0;
    l += n; r += n;
    while(l < r) {
        if (l % 2 == 1) res += tree[l++];
        if (r % 2 == 1) res += tree[--r];
        l >>= 1;
        r >>= 1;
    }
    return res;
}

void update(int k, int u) {
    k += n - 1;
    unsigned long curr = tree[k];
    tree[k] = u;
    long diff = u - curr;
    while (k > 0) {
        k >>= 1;
        tree[k] += diff;
    }
}

int main() {
    cin >> n >> q;
    build();
    vector<unsigned long> res(0);
    for(int i = 0; i < q; ++i) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k & 1) update(l, r);
        else res.push_back(query(l- 1, r));
    }
    for (unsigned long x : res)
        cout << x << endl;
}