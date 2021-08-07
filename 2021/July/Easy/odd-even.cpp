#include <bits/stdc++.h>
using namespace std;
const int maxm = 250;
const int mod = 998'244'353;
int main() {
  vector<int> pow2 = {1};
  for (int i = 0; i < maxm; ++i) {
    pow2.push_back((pow2.back() * 2ll) % mod);
  }
  int t; cin >> t; while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& ai : a) {
      cin >> ai;
    }
    a.push_back(string(m, '0'));
    ++n;
    vector<bitset<maxm>> b(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[i][j] = a[i][j] == '1';
      }
    }
    // https://codeforces.com/bog/entry/68953
    int size = 0;
    vector<bitset<maxm>> basis(m);
    for (auto bi : b) {
      for (auto j = 0; j < m; ++j) {
        if (bi[j]) {
          if (basis[j] == 0) {
            basis[j] = bi;
            ++size;
            break;
          }
          bi ^= basis[j];
        }
      }
    }
    if (!size) {
      cout << 0 << " " << 1 << "\n";
    } else {
      bool f = true;
      for (auto bi : basis) {
        if (bi.count() & 1) {
          f = false;
        }
      }
      if (f) {
        cout << 0 << " " << pow2[size] << "\n";
      } else {
        cout << pow2[size - 1] << " " << pow2[size - 1] << "\n";
      }
    }
  }
  return 0;
}