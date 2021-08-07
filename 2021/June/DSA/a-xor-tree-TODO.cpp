#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& ai : a) cin >> ai;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; ++i) {
    cin >> u >> v; --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root = 0;
  vector<int> root_path_xor(n, -1);
  root_path_xor[root] = a[root];
  auto xor_dfs = [&] (int vertex) -> void {
    for (auto adjacent : g[vertex]) {
      if (root_path_xor[adjacent] == -1) {
        root_path_xor[adjacent] = root_path_xor[vertex] ^ a[adjacent];
        xor_dfs(adjacent);
      }
    }
  };
  xor_dfs(root);

}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int t; cin >> t; while (t--) solve();
  return 0;
}