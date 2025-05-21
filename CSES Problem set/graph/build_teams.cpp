#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n, m;
unordered_set<int> unvisited;
unordered_map<int, vector<int>> neighbors;
vector<int> team_assignment;

void bfs() {
    while(!unvisited.empty()) {
        int start = *unvisited.begin(); unvisited.erase(start);
        queue<int> q; q.push(start);
        team_assignment[start] = 1;
        int nb_team = 2;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front(); q.pop();
                for (int x : neighbors[curr]) {
                    if (unvisited.count(x)) {
                        unvisited.erase(x);
                        team_assignment[x] = nb_team;
                        q.push(x);
                    } else if (team_assignment[x] != nb_team) {
                        cout << "IMPOSSIBLE" << endl;
                        return;
                    }
                }
            }
            nb_team = 3 - nb_team;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << team_assignment[i] << " ";
    return;
}

int main() {
    cin >> n >> m;
    team_assignment.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        unvisited.insert(i + 1);
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        neighbors[v1].push_back(v2);
        neighbors[v2].push_back(v1);
    }
    bfs();
    return 0;
}