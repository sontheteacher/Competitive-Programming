#include <iostream>
#include <queue>
#include <unordered_set>
#include <climits>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

char DOT = '.';
char START = 'A';
char MONSTER = 'M';
char WALL = '#';
int oo = INT_MAX;

const int row[4] = {1, -1, 0, 0};
const int col[4] = {0, 0, 1, -1};
const char dirs[4] = {'D', 'U', 'R', 'L'};

const int mn = 1001;
int M, N;
queue<pii> q;
int dist[mn][mn];
pii A;
char from[mn][mn] = {};
bool possible = false;
string ans;

void retrace(pii node) {
    char origin = from[node.first][node.second];
    while (origin != START) {
        ans.push_back(origin);
        // find index of origin in dirs
        int index = 0;
        while (index < 4 && dirs[index] != origin) {
     		++index;
	}
        node.first -= row[index];
        node.second -= col[index];
        origin = from[node.first][node.second];
    }
}

void check(pii origin, pii dest, char dir) {
    auto [nr, nc] = dest;
    if (nr < 0 || nr >= M || nc < 0 || nc >= N) return;
    int cur_dist = dist[origin.first][origin.second];
    if (cur_dist + 1 < dist[dest.first][dest.second]) {
        dist[dest.first][dest.second] = cur_dist + 1;
        q.push(dest);
        from[dest.first][dest.second] = dir;
    }
}

bool player = false; // false if bfs for monst, true if bfs for A
void bfs() {
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            pii dest = {curr.first + row[i], curr.second + col[i]};
            check(curr, dest, dirs[i]);
        }
        auto [r, c] = curr;
        // if current is player and we hit a boundary, return
        if (player && (r == 0 || c == 0 || r == M - 1 || c == N - 1)) {
            cout << "YES" << endl;
            cout << dist[r][c] << endl;
            retrace(curr);
            possible = true;
            return;
        }
    }
}

int main() {
    // start bfs from each monster first and record dist[i][j]
    // then start bfs from player and record d[i][j] and reachable if d[i][j] < dist[i][j]

    cin >> M >> N;
    // first initialize dist
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            dist[i][j] = oo;
            if (s[j] == WALL) dist[i][j] = 0;
            else if (s[j] == MONSTER) {
                dist[i][j] = 0;
                q.push({i, j});
            } else if (s[j] == START) A = {i, j};
        }
    }
    
    if (A.first == 0 || A.second == 0 || A.first == M - 1 || A.second == N - 1) {
	   cout << "YES\n0\n" << endl;
	  return 0;
	} 
    bfs(); // bfs on monsters
    player = true;
    dist[A.first][A.second] = 0; // Resest distance for starting at A.
    from[A.first][A.second] = START; // terminating location
    q.push(A);
    bfs();
    if (possible) {
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    } else cout << "NO" << endl;
    return 0;
}
