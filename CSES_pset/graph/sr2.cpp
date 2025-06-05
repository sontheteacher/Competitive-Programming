#include <climits>
#include <iostream>
#include <vector>

using namespace std;
int n, m, q;
typedef long long ll;
ll oo = 1e18;

vector<vector<ll>> dist;

void add_edge(int frm, int to, int w) {
	dist[frm][to] = w < dist[frm][to] ? w : dist[frm][to];
	dist[to][frm] = dist[frm][to];
}

void floyd_warshall() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				dist[j][i] = dist[i][j];
			}
		}
	}

}

int main() {
	cin >> n >> m >> q;
	// initialize to all 0
	dist = vector<vector<ll>>(n + 1, vector<ll>(n + 1, oo));
	for (int j = 0; j < m; ++j) {
		int a, b, w;
		cin >> a >> b >> w;
		add_edge(a, b, w);
	}
	for (int i = 0; i < n + 1; ++i) 
		dist[i][i] = 0;
	floyd_warshall();
	vector<ll> res;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] >= oo) {
			res.push_back(-1);
		} else {
			res.push_back(dist[a][b]);
		}
	}
	for (ll x: res)
		cout << x << endl;
	return 0;
}
