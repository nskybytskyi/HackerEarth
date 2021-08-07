#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int t; cin >> t; while (t--) {
    string n;
    cin >> n;
    sort(n.begin(), n.end());
    string x, y;
    const int l = n.length();
    for (int i = 0; i < l; ++i) {
      if (i & 1) {
        x += n[i];
      } else {
        y += n[i];
      }
    }
    cout << stoi(x) + stoi(y) << "\n";
  }
  return 0;
}