#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, q, t;
  cin >> n >> q >> t;
  int lastans = 0;
  auto f = [&] (int a) -> int {
    return (a ^ lastans * 1ll * t) % n;
  };
  vector<bool> u(n);
  u[0] = true;
  vector<vector<int>> g(n);
  function<void(int)> dfs = [&] (int v) -> void {
    u[v] = true;
    for (auto w : g[v]) {
      if (!u[w]) {
        dfs(w);
      }
    }
  };
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int a, b;
      cin >> a >> b;
      int v = f(a), w = f(b);
      if (u[v]) {
        dfs(w);
      } else {
        g[v].push_back(w);
      }
    } else {  // tp == 2
      int a;
      cin >> a;
      int x = f(a);
      lastans = u[x] ? (x + 1) : 0;
      cout << lastans << "\n";
    }
  }
  return 0;
}
