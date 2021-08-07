#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> apsp(vector<vector<int>> d, int n) {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  return d;
}

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n));
  for (auto& di : d)
    for (auto& dij : di)
      cin >> dij;

  vector<vector<int>> m(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (d[i][j] < 40'000)
        m[i][j] = true;

  auto f = [&] (int m) {
    vector<vector<int>> dm(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dm[i][j] = max(m, d[i][j]);
    auto dd = apsp(dm, n);
    int a = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        a += abs(dd[i][j] - d[i][j]);
    return a;
  };

  uniform_int_distribution<int> dist;


  cout << n * n - n << "\n";
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j)
        cout << i + 1 << " " << j + 1 << " " << max(magic, d[i][j]) << "\n";

  return 0;
}