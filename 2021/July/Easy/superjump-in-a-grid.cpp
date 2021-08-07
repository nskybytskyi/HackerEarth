#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007; 
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  vector dp(n, vector(m, 0));
  dp[0][0] = a[0][0] == '0';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '0') {
        for (int k = i - 1; k >= 0; --k) {
          if (a[k][j] == '0') {
            dp[i][j] += dp[k][j];
            dp[i][j] %= mod;
            break;
          }
        }
        for (int k = j - 1; k >= 0; --k) {
          if (a[i][k] == '0') {
            dp[i][j] += dp[i][k];
            dp[i][j] %= mod;
            break;
          }
        }
      }
    }
  }
  cout << dp[n - 1][m - 1] << "\n";
  return 0;
}