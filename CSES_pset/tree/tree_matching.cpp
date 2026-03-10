#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>

using std::vector, std::cin, std::cout, std::pair, std::ios, std::endl;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool matched[MAXN];
int ans = 0;

void dfs(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      if (!matched[v] && !matched[u]) {
        matched[v] = matched[u] = true;
        ans++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  if (!(cin >> n))
    return 0;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Start DFS from node 1 (arbitrary root)
  dfs(1, 0);

  cout << ans << endl;

  return 0;
}
