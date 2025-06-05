#include <iostream>
#include <vector>

using namespace std;

const int N = 2*1e5;
int n = 0, q = 0;
// your segment tree stored inarray
// first node is node 1 (omit node 0)
// child of tree[k] are tree[2k] and tree[2k + 1]
// parent of tree[k] is tree[k//2]
unsigned long tree[2 * N];

void build() {
    for(int i = 0; i < n; ++i) 
        cin >> tree[i + n];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
}

// sum on interval [l, r), using 0 index
unsigned long query(int l, int r) {
    unsigned long res = 0;
    l += n; r += n; // shift by n
    while(l < r) {
        // if l is a right node, add that and move to the right
        // if r is a right node, move left, add that
        if (l % 2 == 1) res += tree[l++];
        if (r % 2 == 1) res += tree[--r];
        l >>= 1;
        r >>= 1;
    }
    return res;
}

// update tree[k] = u and update the tree
void update(int k, int u) {
    //k^1 gives 1 if k is even or 0 if k is odd, ie gives the neighbor of k
    for (tree[k += n - 1] = u; k > 1; k >>= 1) tree[k >> 1] = tree[k] + tree[k^1];
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