#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int main() {
  int t; cin >> t; while (t--) {
    int z, o, k;
    cin >> z >> o >> k;
    vector dp(z + 2, vector(o + 2, vector(o + z + 4, 0)));
    dp[1][0][1] = dp[0][1][1] = 1;
    for (int i = 0; i <= z; ++i) {
      for (int j = 0; j <= o; ++j) {
        for (int l = 0; l <= z + o; ++l) {
          // append zero
          dp[i + 1][j][max(i + 1, l)] += dp[i][j][l];
          dp[i + 1][j][max(i + 1, l)] %= mod;
          // append one
          dp[i][j + 1][l + 1] += dp[i][j][l];
          dp[i][j + 1][l + 1] %= mod;
        }
      }
    }
    int sum = 0;
    for (int l = k; l <= z + o; ++l) {
      sum += dp[z][o][l];
      sum %= mod;
    }
    cout << sum << "\n";
  }
  return 0;
}
