#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(n);
    for (auto& [v, p] : vp) {
      cin >> v >> p;
    }
    vector dp(2, vector(m + 1, 0));
    for (auto [v, p] : vp) {
      vector ndp(2, vector(m + 1, 0));
      for (int j = 0; j <= m; ++j) {
        ndp[0][j] = dp[0][j];
        ndp[1][j] = dp[1][j];
      }
      for (int j = p; j <= m; ++j) {
        ndp[0][j] = max(ndp[0][j], dp[0][j - p] + v);
        ndp[1][j] = max(ndp[1][j], dp[1][j - p] + v);
      }
      for (int j = p / 2; j <= m; ++j) {
        ndp[1][j] = max(ndp[1][j], dp[0][j - p / 2] + v);
      }
      swap(dp, ndp);
    }
    cout << max(dp[0][m], dp[1][m]) << "\n";
  }
  return 0;
}
