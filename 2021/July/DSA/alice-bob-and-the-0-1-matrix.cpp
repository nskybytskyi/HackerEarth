#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> b(n);
  for (auto& bi : b) {
    cin >> bi;
  }
  int c = 0;
  for (int j = 0; j < m; ++j) {
    bool all = true;
    for (int i = 0; i < n; ++i) {
      all &= b[i][j] == '1';
    }
    if (all) {
      ++c;
    }
  }
  cout << c << "\n";
  return 0;
}
