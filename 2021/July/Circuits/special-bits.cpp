#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int t; cin >> t; while (t--) {
    int64_t l, r;
    int k;
    cin >> l >> r >> k;
    int64_t m = 0;
    for (int i = 60; i >= 0; --i) {
      if ((m | (1ll << i)) > r) {  // cannot take 1 because of [l, r] bounds
        ;
      } else if ((m | (1ll << i)) <= l) {  // cannot take 0 because of [l, r] bounds
        m |= 1ll << i;
        --k;
      } else {  // can take both 0 and 1 according to [l, r] bounds
        if (i < k) {  // cannot take 0 because of set bits count
          m |= 1ll << i;
          --k;
        } else if (!k) {  // cannot take 0 because of set bits count
          ;
        } else {  // can take both 0 and 1 according to set bits count
          // how many bits we will have to take if we take 0 now
          if (m >> i == l >> i) {  // m is equal to l so far
            int s = 0;
            int j = i - 1;
            while (j >= 0 && (l & (1ll << j))) {
              ++s;
              --j;
            }
            while (j >= 0) {
              if (l & (1ll << j)) {
                ++s;
                break;
              } else {
                --j;
              }
            }
            if (s > k) {  // cannot take 0 because of set bits count
              m |= 1ll << i;
              --k;
            } else {  // can take 0
              ;
            }
          }
        }
      }
    }
    cout << (k == 0 ? m : -1) << "\n";
  }
  return 0;
}
