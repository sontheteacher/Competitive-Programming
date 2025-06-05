#include <iostream>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;

ll oo = LONG_LONG_MAX ;
ll d[100001] = {};
bool inQueue[100001] = {};
vector<vector<pair<int, int> >> graph;
int n, m;

void addEdge(int frm, int to, int weight) {
	graph[frm].push_back({to, weight});
}


void shortestPathFaster() {
	queue<int> q;
	q.push(1);
	inQueue[1] = true;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		inQueue[u] = false;
	

		for (size_t i = 0; i < graph[u].size(); ++i) {
			int v= graph[u][i].first;
			int weight =  graph[u][i].second;
			
			if (d[v] > d[u] + weight) {
				d[v] = d[u] + weight;
			

				if (!inQueue[v]){
					q.push(v);
					inQueue[v] = true;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 2; i <= n; ++i) {
		d[i] = oo;
	}
	graph.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		addEdge(a, b, w);
	}
	shortestPathFaster();
	for (int i = 1; i <= n; ++i) {
		cout << d[i] << " ";
	}
	return 0;

}
