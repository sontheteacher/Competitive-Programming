#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int n, m;
unordered_map<int, vector<int>> graph;
unordered_set<int> unvisited;
vector<int> parents;

bool dfs(int start) {
    for (int x : graph[start]) {
        if (x == parents[start]) continue;
        else if (unvisited.count(x)) {
            unvisited.erase(x);
            parents[x] = start;
            if (dfs(x)) return true;
        } else { // hit a cycle
            int curr = start, goal = x;
            vector<int> sol = {goal, curr};
            while (curr != goal) {
                curr = parents[curr];
                sol.push_back(curr);
            }
            cout << sol.size() << endl;
            for (int x  : sol) cout << x << " ";
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    parents.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        unvisited.insert(i + 1);
        parents[i + 1] = 0; // initialize all parents to 0
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bool flag = false;
    while (!unvisited.empty()) {
        int start = *unvisited.begin();
        unvisited.erase(start);
        flag |= dfs(start);
        if (flag) break;
    }
    if (!flag) cout << "IMPOSSIBLE" << endl;
}