#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAX = 4001001;
vector<long long> fact(MAX), inv_fact(MAX);
typedef long long ll;

ll modpow(ll a, ll b) {
    // compute a^b modulo MOD
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1; 
        // shift b in place, b >> 1 just return the result without changing
    }
    return res;
}

void precompute(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[N] = modpow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; --i){
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int N = A + B + C + D;
    ll res = 0;
    precompute(N);
    for(int i = A; i <= A + B; ++i) {
        ll extra = nCk(i - 1, A - 1) * nCk(N - i, C) % MOD;
        res += extra;
    }
    cout << res % MOD << endl;
}