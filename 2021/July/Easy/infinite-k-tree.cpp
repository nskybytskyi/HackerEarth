#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int k, q;
  cin >> k >> q;
  unordered_map<int64_t, int64_t> pw;
  auto get = [&] (int64_t node) -> int64_t {
    if (!pw.count(node)) {
      pw[node] = 1;
    }
    return pw[node];
  };
  auto inc = [&] (int64_t node, int64_t delta) -> void {
    if (!pw.count(node)) {
      pw[node] = 1;
    }
    pw[node] += delta;
  };
  auto rp = [&] (int64_t v) -> vector<int64_t> {
    vector<int64_t> rp = {v};
    while (rp.back() != 1) {
      rp.push_back(rp.back() / k);
    }
    return rp;
  };
  auto lcap = [&] (int64_t u, int64_t v) -> pair<vector<int64_t>, vector<int64_t>> {
    auto rpu = rp(u), rpv = rp(v);
    while (!rpu.empty() && !rpv.empty() && rpu.back() == rpv.back()) {
      rpu.pop_back();
      rpv.pop_back();
    }
    return {rpu, rpv};
  };
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int64_t u, v;
      cin >> u >> v;
      auto [lcapu, lcapv] = lcap(u, v);
      int64_t w = 0;
      for (auto node : lcapu) {
        w += get(node);
      }
      for (auto node : lcapv) {
        w += get(node);
      }
      cout << w << "\n";
    } else {  // t == 2
      int64_t u, v, w;
      cin >> u >> v >> w;
      auto [lcapu, lcapv] = lcap(u, v);
      for (auto node : lcapu) {
        inc(node, w);
      }
      for (auto node : lcapv) {
        inc(node, w);
      }
    }
  }
  return 0;
}