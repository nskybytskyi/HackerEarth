#include <bits/stdc++.h>
using namespace std;
__int128_t read() {
    __int128_t x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128_t x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int main() {
  int t; cin >> t; while (t--) {
    int n;
    cin >> n;
    vector<__int128_t> a(n);
    for (auto& ai : a) {
      ai = read();
    }
    int q;
    cin >> q;
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        int i, v;
        cin >> i >> v;
        --i;
        a[i] = v;
      } else {  // t == 2
        int l, r;
        cin >> l >> r;
        --l, --r;
        __int128_t s = 0;
        for (__int128_t i = l; i <= r; ++i) {
          s += a[i] * (i - l + 1) * (r - i + 1);
        }
        print(s);
        cout << "\n";
      }
    }
  }
  return 0;
}
