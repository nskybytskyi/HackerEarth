#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int t; cin >> t; while (t--) {
    int k;
    cin >> k;
    int pp = min(k, 6);
    for (int rest = 0; rest < pow(10, pp); ++rest) {
      int s = k - pp;
      int p = 1;
      int r = rest;
      for (int i = 0; i < pp; ++i) {
        int d = r % 10;
        s += d;
        p *= d;
        r /= 10;
      }
      if (p && p >= s) {
        cout << string(k - pp, '1') + to_string(rest) << "\n";
        break;
      }
    }
  }
  return 0;
}