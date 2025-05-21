#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int n, m;
unordered_map<int, vector<int>> graph;
unordered_set<int> unvisited_nodes;
vector<int> representatives;

void bfs() {
    while (!unvisited_nodes.empty()) {
        queue<int> q;
        int start = *unvisited_nodes.begin();
        unvisited_nodes.erase(start);
        // GET ONE NODE AS REPRESENTATIVE FOR CONNECTED COMPONENTS
        representatives.push_back(start); 
        q.push(start); // some nodes as start
        // now do bfs
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for (int n : graph[curr]) {
                // only add nodes to q if unvisited
                if (unvisited_nodes.count(n)) {
                    q.push(n);
                    unvisited_nodes.erase(n);
                }
            }
        }
    }
    // now we want to get all 2 elements combinations of representatives
    int c = representatives.size();
    cout << c - 1 << endl;
    for (int i = 0; i < c - 1; ++i) {
        cout << representatives[i] << " " << representatives[i + 1] << endl;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        unvisited_nodes.insert(i + 1);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // insert ineighbor in adjacency list
    }
    bfs();
    return 0;
}