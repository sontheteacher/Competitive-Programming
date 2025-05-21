#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

const pair<int, int> DIRS[4] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

int encode(int r, int c, int n) {
    return n * c + r;
}

void bfs(const vector<string>& map, pair<int, int> node, unordered_set<int>& visited) {
    // start bfs from the current node to find all nodes in the current room
    int n = map.size(), m = map[0].size();
    queue<pair<int, int>> q;
    q.push(node);
    while (q.size()) {
        auto [r, c] = q.front(); q.pop(); // structured binding
        for (const auto [dr, dc] : DIRS) {
            int nr = r + dr, nc = c + dc;
            int code = encode(nr, nc, n);
            if (!(nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == '#' || 
                visited.find(code) != visited.end())) {
                q.push({nr, nc});
                visited.insert(code);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    unordered_set<int> visited;
    int res = 0;
    for (int i = 0; i < n; ++i) 
        cin >> map[i];
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            // this is a new room if current is '.' and it''s not visited
            char curr = map[r][c];
            int code = encode(r, c, n);
            if (curr == '.' && visited.find(code) == visited.end()) {
                visited.insert(code);
                bfs(map, {r, c}, visited);
                ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}