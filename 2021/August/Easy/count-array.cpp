#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
pair<vector<bool>, vector<int>> sieve(int max) {
  vector<bool> is_prime(max, true);
  is_prime[0] = is_prime[1] = false;
  for (int d = 2; d * d < max; ++d) {
    if (is_prime[d]) {
      for (int m = d * d; m < max; m += d) {
        is_prime[m] = false;
      }
    }
  }
  vector<int> primes;
  for (int d = 2; d < max; ++d) {
    if (is_prime[d]) {
      primes.push_back(d);
    }
  }
  return {is_prime, primes};
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int p, q;
  cin >> p >> q;
  auto [is_prime, primes] = sieve(p + 1);
  const int log = log2(p);
  vector<map<int, int>> dp(log + 1);
  dp[0][1] = 1;
  for (auto prime : primes) {
    dp[1][prime] = 1;
  }
  for (int n = 2; n <= log; ++n) {
    for (int first : primes) {
      for (auto [prod_rest, cnt] : dp[n - 2]) {
        auto prod = first * 1ll * prod_rest * 1ll * first;
        if (prod > p) {
          break;
        }
        dp[n][prod] += cnt;
        dp[n][prod] %= mod;
      }
    }
  }
  vector<int> ps(log + 1);
  for (int n = 1; n <= log; ++n) {
    ps[n] = ps[n - 1];
    for (auto [prod, cnt] : dp[n]) {
      ps[n] += cnt;
      ps[n] %= mod;
      }
  }
  while (q--) {
    int n;
    cin >> n;
    cout << ps[min(n, log)] << " ";
  }
  cout << "\n";
  return 0;
}