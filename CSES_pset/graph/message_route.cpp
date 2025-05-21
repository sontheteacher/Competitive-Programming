#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n, m;
unordered_set<int> unvisited;
unordered_map<int, vector<int>> neighbors;
unordered_map<int, int> parents;

void bfs() {
    int start = 1;
    unvisited.erase(start);
    queue<int> q; q.push(start);
    while(!q.empty()) {
        // process the current level
        int sz = q.size();
        while(sz--) {
            int curr = q.front(); q.pop();
            // process the neighbors
            for (int nei : neighbors[curr]) {
                if (n == nei) {
                    parents[nei] = curr; // need this
                    // if we found Maija, traceback
                    vector<int> sol;
                    while (nei != start) {
                        sol.push_back(nei);
                        nei = parents[nei];
                    }
                    sol.push_back(1);
                    cout << sol.size() << endl;
                    for (auto it = sol.rbegin(); it != sol.rend(); ++it)
                        cout << *it << " ";
                    return;
                }
                // else check if neighbor is valid
                else if (unvisited.count(nei)) {
                    unvisited.erase(nei);
                    q.push(nei);
                    parents[nei] = curr;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    cin >> n >> m;
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