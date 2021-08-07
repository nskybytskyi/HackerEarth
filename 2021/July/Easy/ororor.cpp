#include <bits/stdc++.h>
using namespace std;
const int64_t w = 32;
inline int64_t val(const vector<int64_t>& cnt) {
  int64_t y = 0;
  for (int64_t bit = 0; bit < w; ++bit) {
    if (cnt[bit]) {
      y |= 1ll << bit;
    }
  }
  return y;
}
int main() {
  int64_t t; cin >> t; while (t--) {
    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> a(n);
    for (auto& ai : a) {
      cin >> ai;
    }
    vector<pair<int64_t, int64_t>> lr;
    vector<int64_t> cnt(w);
    {
      int64_t l = 0, r = 0; 
      while (l < n) {
        if (val(cnt) < x) {
          if (r < n) {
            for (int64_t bit = 0; bit < w; ++bit) {
              if (a[r] & (1ll << bit)) {
                ++cnt[bit];
              }
            }
            ++r;
          } else {
            break;
          }
        } else {
          lr.emplace_back(l, r);
          for (int64_t bit = 0; bit < w; ++bit) {
            if (a[l] & (1ll << bit)) {
              --cnt[bit];
            }
          }
          ++l;
        }
      }
    }
    int64_t m = n;
    for (auto [l, r] : lr) {
      m = min(m, r - l);
    }
    vector<pair<int64_t, int64_t>> fil;
    for (auto [l, r] : lr) {
      if (r - l == m) {
        fil.emplace_back(l, r);
      }
    }
    cout << fil.size() << "\n";
    for (auto [l, r] : fil) {
      cout << l + 1 << " " << r << "\n";
    }
  }
  return 0;
}