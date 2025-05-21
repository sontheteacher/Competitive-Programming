#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2 * 1e5;
int n, q;
int tree[2* N];


void build(){
    for (int i = 0; i < n; ++i)
        cin >> tree[i + n];
    for (int i = n - 1; i > 0; --i)
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

int query(int l, int r) {
    // query minimum in range [l, r)
    l += n; r += n;
    int res = 1e9;
    while(l < r) {
        if (r & 1) res = min(res, tree[--r]);
        if (l & 1) res = min(res, tree[l++]);
        l >>= 1;
        r >>= 1;
    }
    return res;
}

// void update(int k, int u) {
//     k += n - 1;
//     tree[k] = u;
//     // update parents as long as the update decreases the parents
//     for (k >>= 1; k > 0; k >>= 1) {
//         unsigned newVal = min(tree[2*k], tree[2*k + 1]);
//         if (tree[k] == newVal) break; // if parent stay the same then break
//         else tree[k] = newVal; // update and keep 
//     }
// }

void update(int k, int u) {
    k += n - 1;
    tree[k] = u;
    // update parents as long as the update decreases the parents
    for (k >>= 1; k > 0; k >>= 1) {
        if (tree[k] <= u) break; // if parent stay the same then break
        else tree[k] = u; // update and keep -> THIS DOESN"T WORK SINCE PARENTS COULD INCREASE
    }
}

// void update(int k, int u) {
//     for(tree[k += n - 1] = u; k > 1; k >>= 1) tree[k >> 1] = min(tree[k], tree[k ^ 1]);
// }

int main() {
    cin >> n >> q;
    build();
    vector<int> res(0);
    for(int i = 0; i < q; ++i) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k & 1) update(l, r);
        else res.push_back(query(l-1, r));
    }
    for (auto x : res) cout << x << endl;
}