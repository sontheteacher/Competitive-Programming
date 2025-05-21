#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int H, W, N, Q;
    cin >> H >> W >> N;
    unordered_map<int, unordered_set<int>> trash_map;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        trash_map[x - 1].insert(y - 1);
        trash_map[y + H - 1].insert(x - 1); // hash column since x < H
    }
    cin >> Q;
    vector<int> res(0);
    for (int i = 0; i < Q; i++) {
        int type, z; cin >> type >> z;
        --z;
        if (type == 1) {
            int cnt = trash_map[z].size(); // index in row
            res.push_back(cnt);
            for (int y : trash_map[z]) trash_map[y + H].erase(z);
            trash_map.erase(z);
        } else if (type == 2) {
            int cnt = trash_map[z + H].size(); // index in column
            res.push_back(cnt);
            for (int x : trash_map[z + H]) trash_map[x].erase(z);
            trash_map.erase(z + H);
        }
    }
    for (auto x : res) cout << x << endl;
    return 0;
}