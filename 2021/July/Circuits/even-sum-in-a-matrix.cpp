#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector a(n, vector(m, 0));
  for (auto& ai : a) {
    for (auto& aij : ai) {
      cin >> aij;
    }
  }
  vector ps(n + 1, vector(m + 1, 0));
  vector<bitset<1 << 11>> bps(n + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ps[i + 1][j + 1] = (a[i][j] & 1) ^ ps[i + 1][j] ^ ps[i][j + 1] ^ ps[i][j];
      bps[i + 1][j] = ps[i + 1][j + 1];
    }
  }
  int64_t cnt = 0;
  for (int i0 = 0; i0 < n; ++i0) {
    for (int i1 = i0; i1 < n; ++i1) {
      int c1 = (bps[i0] ^ bps[i1 + 1]).count();
      int c0 = m + 1 - c1;
      cnt += c1 * (c1 - 1) >> 1;
      cnt += c0 * (c0 - 1) >> 1;
    }
  }
  cout << cnt << "\n";
  return 0;
}
