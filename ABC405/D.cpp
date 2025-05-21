#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main() {
    const char UP = '^';
    const char DOWN = 'v';
    const char LEFT = '<';
    const char RIGHT = '>';
    const char WALL = '#';
    const char EXIT = 'E';
    const map<pair<int, int>, char> DIRS = {
        {{-1, 0} , DOWN}, 
        {{1, 0} , UP}, 
        {{0, 1} , LEFT}, 
        {{0, -1} , RIGHT}
    };
    
    int H, W;
    cin >> H >> W;
    vector<string> map(H);
    vector<vector<bool>> visited(H, vector<bool>(W));

    for (int i = 0; i < H; ++i) {
        cin >> map[i];
    }
    // DO BFS with all the exit and expand
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (map[i][j] == EXIT) {
                q.push({i, j});
                visited[i][j] = true;
            } else if (map[i][j] == WALL) {
                visited[i][j] = true;
            }
        }
    }

    while (q.size() > 0) {
        auto [r, c] = q.front();
        q.pop();
        for (const auto& [coord, ch] : DIRS) {
            int dr = coord.first;
            int dc = coord.second;
            int nr = r + dr; 
            int nc = c + dc;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W || visited[nr][nc]){
                continue;
            } else {
                map[nr][nc] = ch;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < H; i++) {
        cout << map[i] << endl;
    }
    return 0;
}