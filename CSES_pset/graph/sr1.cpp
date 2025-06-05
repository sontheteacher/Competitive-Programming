#include <iostream>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;

ll oo = LONG_LONG_MAX ;
ll d[100001] = {};
bool processed[100001] = {};
vector<vector<pair<int, int> >> adj;
int n, m;

void addEdge(int frm, int to, int weight) {
	adj[frm].push_back({to, weight});
}


void djikstra() {
	priority_queue<pair<ll, int>> q;
	q.push({0,1});

	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (processed[u]) continue;
		processed[u] = true;
		
		for(auto p : adj[u]) {
			int b = p.first, w = p.second;
			if (d[u] + w < d[b]) {
				d[b] = d[u] + w;
				q.push({-d[b], b});
			}	
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 2; i <= n; ++i) {
		d[i] = oo;
	}
	adj.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		addEdge(a, b, w);
	}
	djikstra();
	for (int i = 1; i <= n; ++i) {
		cout << d[i] << " ";
	}
	return 0;
}
