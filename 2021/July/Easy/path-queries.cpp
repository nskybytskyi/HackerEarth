#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int64_t> ans;
    ans.reserve(q);
    int e = 0, o = 0;
    for (auto& ai : a) {
      cin >> ai;
      ai &= 1;
      if (ai & 1) {
        ++o;
      } else {
        ++e;
      }
    }
    vector<vector<int>> g(n);
    for (int _ = 1; _ < n; ++_) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    while (q--) {
      int u, v;
      cin >> u >> v;
      --u;
      v &= 1;
      if (a[u] & 1) {
        --o;
      } else {
        --e;
      }
      a[u] = v;
      if (a[u] & 1) {
        ++o;
      } else {
        ++e;
      }
      ans.push_back((e + e * 1ll * e) / 2 + (o + o * 1ll * o) / 2);
    }
    for (auto ansi : ans) {
      cout << ansi << " ";
    }
    cout << "\n";
  }
  return 0;
}