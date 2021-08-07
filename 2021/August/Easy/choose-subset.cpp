#include <bits/stdc++.h>
using namespace std;
// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
int lis(const vector<int>& a) {
  int n = a.size();
  const int kInfinity = numeric_limits<int>::max();
  vector<int> d(n + 1, kInfinity);
  d[0] = -kInfinity;
  for (int i = 0; i < n; ++i) {
    int j = distance(d.begin(), upper_bound(d.begin(), d.end(), a[i]));
    if (d[j - 1] < a[i] && a[i] < d[j]) {
        d[j] = a[i];
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (d[i] < kInfinity) {
      ans = i;
    }
  }
  return ans;
}
int main() {
  int t; cin >> t; while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i) {
      cin >> ab[i].first;
    }
    for (int i = 0; i < n; ++i) {
      cin >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      b[i] = ab[i].second;
    }
    cout << lis(b) << "\n";
  }
  return 0;
}
