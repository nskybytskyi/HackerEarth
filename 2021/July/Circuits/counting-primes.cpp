#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto& xi : x) {
    cin >> xi;
  }
  vector<int> y(n);
  for (auto& yi : y) {
    cin >> yi;
  }
  auto factorize = [&] (int xi) -> vector<int> {
    vector<int> factors;
    for (int d = 2; d * d <= xi; ++d) {
      if (xi % d == 0) {
        factors.push_back(d);
        while (xi % d == 0) {
          xi /= d;
        }
      }
    }
    if (xi > 1 && (factors.empty() || factors.back() != xi)) {
      factors.push_back(xi);
    }
    return factors;
  };
  for (int i = 0; i < n; ++i) {
    int c = 0;
    for (auto factor : factorize(x[i])) {
      for (int j = i - 1; j >= i - y[i]; --j) {
        if (x[j] % factor == 0) {
          ++c;
          break;
        } 
      }
    }
    cout << c << " ";
  }
  cout << "\n";
  return 0;
}
