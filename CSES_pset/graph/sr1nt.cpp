#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
ll oo = LONG_LONG_MAX;
vector<vector<pair<int, int> >> adj;
ll dist[100001] = {};
bool processed[100001] = {};

void add_edge(int frm,  int to, int weight) {
	adj[frm].push_back({to, weight});
}

void djikstra() {
	priority_queue<pair<ll, int>> q;
	q.push({0, 1});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;

		for (auto u : adj[a]) {
			int b = u.first;
			int w = u.second;
			if (dist[a] + w < dist[b]) {
				dist[b] = dist[a] + w; 
			}
			q.push({-dist[b], b});
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 2; i <= n; ++i) {
		dist[i] = oo;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		add_edge(a, b, w);
	}
	djikstra();
	for (int i = 0; i < n; ++i) {
		cout << dist[i + 1] << " ";
	}
}
