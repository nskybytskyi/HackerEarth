#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) { }
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<Point> ps(k);
  for (auto& p : ps) {
    cin >> p.x >> p.y;
  }
  sort(ps.begin(), ps.end(), [] (const auto& a, const auto& b) -> bool {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
  });
  vector<int> pmin(k + 1, n + 1), pmax(k + 1, -1);
  for (int i = 0; i < k; ++i) {
    pmin[i + 1] = min(pmin[i], ps[i].y);
    pmax[i + 1] = max(pmax[i], ps[i].y);
  }
  vector<int> smin(k + 1, n + 1), smax(k + 1, -1);
  for (int i = k - 1; i >= 0; --i) {
    smin[i] = min(smin[i + 1], ps[i].y);
    smax[i] = max(smax[i + 1], ps[i].y);
  }
  auto can = [&] (int z) -> bool {
    // [l, r]
    for (int l = 0, r = 0; r < k; ++r) {
      while (ps[l].x + z < ps[r].x - z) {
        ++l;
      }
      if (min(pmin[l], smin[r + 1]) + z >= max(pmax[l], smax[r + 1]) - z) {
        return true;
      }
    }
    return false;
  };
  int lo = -1, hi = n;
  while (lo + 1 < hi) {
    int mi = (lo + hi) / 2;
    if (can(mi)) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  cout << hi << "\n";
  return 0;
}
