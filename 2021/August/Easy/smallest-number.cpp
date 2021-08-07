#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t; while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int a = 0;
    string r;
    for (auto c : s) {
      if (c == '2') {
        ++a;
      } else {
        r += c;
      }
    }
    auto i = r.find('3');
    if (i != string::npos) {
      cout << r.substr(0, i) << string(a, '2') << r.substr(i) << "\n";
    } else {
      cout << r << string(a, '2') << "\n";
    }
  }
  return 0;
}
