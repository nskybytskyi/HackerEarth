#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t; cin >> t; while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
      cin >> ai;
    }
    a.push_back(-1);
    vector<pair<int, int>> b;
    int cv = -1, cl = 0;
    for (auto ai : a) {
      if (ai == cv) {
        ++cl;
      } else {
        if (cl) {
          b.emplace_back(cv, cl);
        }
        cl = 1;
        cv = ai;
      }
    }
    int bc = b.size();
    if (b[0].first) {
      if (bc & 1) {
        cout << (bc + 1) / 2 << "\n";
      } else {
        cout << (bc + 2) / 2 << "\n";
      }
    } else {
      if (bc & 1) {
        cout << (bc + 1) / 2 << "\n";
      } else {
        cout << bc / 2 << "\n";
      }
    }
  }
  return 0;
}