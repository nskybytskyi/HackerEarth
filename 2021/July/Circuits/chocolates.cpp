#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  vector dp(n, vector(n, 0));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
  }
  for (int m = 1; m < n; ++m) {
    for (int l = 0, r = m; r < n; ++l, ++r) {
      if (a[l] == a[r]) {
        for (int dl = 1; dl <= k && !dp[l][r]; ++dl) {
          for (int dr = 1; dr <= k && !dp[l][r]; ++dr) {
            if (l + dl <= r - dr) {
              dp[l][r] |= dp[l + dl][r - dr];
            }
          }
        }
      }
    }
  }
  cout << (dp[0][n - 1] ? "YES" : "NO") << "\n";
  return 0;
}
