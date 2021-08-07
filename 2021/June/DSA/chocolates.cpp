#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 998'244'353;
const int64_t root_pw = 1 << 23;
int64_t modpow(int64_t b, int64_t e) {
  int64_t r = 1;
  while (e) {
    if (e & 1) {
      r *= b;
      r %= mod;
    }
    b *= b;
    b %= mod;
    e >>= 1;
  }
  return r;
}
const int64_t root = modpow(3, 7 * 17);
inline int64_t modinv(int64_t b) {
  return modpow(b, mod - 2);
}
const int64_t root_1 = modinv(root);
void ntt(vector<int64_t> & a, bool invert) {
    int64_t n = a.size();
    for (int64_t i = 1, j = 0; i < n; i++) {
        int64_t bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int64_t len = 2; len <= n; len <<= 1) {
        int64_t wlen = invert ? root_1 : root;
        for (int64_t i = len; i < root_pw; i <<= 1) {
          wlen *= wlen;
          wlen %= mod;
        }
        for (int64_t i = 0; i < n; i += len) {
            int64_t w = 1;
            for (int64_t j = 0; j < len / 2; j++) {
                int64_t u = a[i+j], v = (a[i+j+len/2] * w) % mod;
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w *= wlen;
                w %= mod;
            }
        }
    }
    if (invert) {
        int64_t n_1 = modinv(n);
        for (int64_t & x : a) {
          x *= n_1;
          x %= mod;
        }
    }
}
vector<int64_t> multiply(vector<int64_t> a, vector<int64_t> b) {
    int64_t n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int64_t i = 0; i < n; i++) {
      a[i] *= b[i];
      a[i] %= mod;
    }
    ntt(a, true);
    return a;
}
void solve() {
  int64_t n, m; cin >> n >> m; --m; m %= mod;
  vector<int64_t> a(n);
  for (auto& ai : a) cin >> ai;
  reverse(a.begin(), a.end());
  vector<int64_t> b(n);
  b[0] = 1;
  for (int64_t i = 1; i < n; ++i) {
    b[i] = b[i - 1];
    b[i] *= m + i - 1;
    b[i] %= mod;
    b[i] *= modinv(i);
    b[i] %= mod;
  }
  auto c = multiply(a, b);
  c.resize(n);
  reverse(c.begin(), c.end());
  for (int i = 0; i < n; ++i) {
    cout << c[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t t; cin >> t; while (t--) solve();
  return 0;
}