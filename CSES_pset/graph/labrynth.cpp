#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;



const pair<int, int> DIRS[4] = {
    {-1, 0}, // UP
    {1, 0}, // DOWN
    {0, -1}, // LEFT
    {0, 1}, // RIGHT
};

int encode(int r, int c, int n) {
    return n * c + r;
}

bool is_valid(int x, int y, const vector<string>& map, const unordered_set<int>& visited) {
    int n = map.size(), m = map[0].size();
    return (x >= 0 && x < n && y >= 0 && y < m && map[x][y] != '#' && visited.count(encode(x, y, n)) == 0);
}

void backtrack(int x, int y, const vector<string>& steps, stack<char>& ans) {
    if (steps[x][y] != 'X') {
        char ch = steps[x][y];
        ans.push(ch);
        if (ch == 'U') backtrack(x + 1, y, steps, ans); //if up then move down for backtrack
        else if (ch == 'D') backtrack(x - 1, y, steps, ans);
        else if (ch == 'R') backtrack(x, y - 1, steps, ans);
        else if (ch == 'L') backtrack(x, y + 1, steps, ans);
    }
}

bool bfs(const vector<string>& map, pair<int, int> start) {
    bool flag = false; // flag for finding path to B
    unordered_set<int> visited; // visited node
    int n = map.size();
    // IMPORTANT TO INITIALIZE TO MAP FOR SIZE, or use vector<vector<char>>...
    vector<string> steps = map; // steps matrix to keep track of the steps
    auto [r, c] = start; // has to use auto
    steps[r][c] = 'X'; // begin
    int code = encode(r, c, n); // hash the start
    visited.insert(code);
    queue<pair<int, int>> q; q.push(start); // queue for frontier
    while (!q.empty()) {
        tie(r, c) = q.front(); q.pop(); // current node with shortest distance
        if (map[r][c] == 'B') {
            flag = true;
            break;
        }
        if (is_valid(r - 1, c, map, visited)) {
            visited.insert(encode(r - 1, c, n));
            steps[r - 1][c] = 'U';
            q.push({r - 1, c});
        }
        if (is_valid(r + 1, c, map, visited)) {
            visited.insert(encode(r + 1, c, n));
            steps[r + 1][c] = 'D';
            q.push({r + 1, c});
        }
        if (is_valid(r, c - 1, map, visited)) {
            visited.insert(encode(r, c - 1, n));
            steps[r][c - 1] = 'L';
            q.push({r, c - 1});
        }
        if (is_valid(r, c + 1, map, visited)) {
            visited.insert(encode(r, c + 1, n));
            steps[r][c + 1] = 'R';
            q.push({r, c + 1});
        }
    }
    if (flag) {
        stack<char> ans;
        backtrack(r, c, steps, ans);
        // print(answer)
        cout << "YES" << endl << ans.size() << endl;
        while(!ans.empty()) {
            cout << ans.top(); 
            ans.pop();
        }
        return true;
    }
    cout << "NO" << endl;
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> A, B;
    vector<string> map(n);
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'A') {
                A = {i, j};
                break;
            }
        }
    }
    bfs(map, A);
    return 0;
}