#include <bits/stdc++.h>
using namespace std;
vector<int64_t> a = {0, 1};
void solve() {
  int64_t n;
  cin >> n;
  int64_t m = n;
  int i = distance(a.begin(), lower_bound(a.begin(), a.end(), n));
  if (i) {
    m = min(m, n - a[i - 1]);
  }
  if (i < int(a.size())) {
    m = min(m, a[i] - n);
  }
  cout << m << "\n";
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int h = 16;
  for (int k = 0; k <= h; ++k) {
    for (int64_t m = 1; m < (1 << k); m += 2) {
      int64_t r = 0;
      for (int i = 0; i < k; ++i) {
        r <<= 1;
        if (m & (1 << i)) {
          r |= 1;
        }
      }
      a.push_back((r << k) | m);
      a.push_back((r << (k + 1)) | m);
      a.push_back((r << (k + 1)) | (1 << k) | m);
    }
  }
  sort(a.begin(), a.end());
  int t; cin >> t; while (t--) solve();
  return 0;
}