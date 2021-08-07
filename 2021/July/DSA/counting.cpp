#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *find_by_order, order_of_key
int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  string x;
  int m;
  cin >> x >> m;
  vector<tuple<int, int, int>> kli(m);
  {
    int ii = 0;
    for (auto& [k, l, i] : kli) {
      cin >> k >> l;
      i = ii;
      ++ii;
    }
  }

  const int n = x.length();
  const int log = 20;
  vector<vector<int>> st(log, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    st[0][i] = i;
  }
  for (int j = 1, l = 1; j < log; ++j, l <<= 1) {
    for (int i = 0; i < n; ++i) {
      if (i + l <= n) {
        if (x[st[j - 1][i]] >= x[st[j - 1][i + l]]) {
          st[j][i] = st[j - 1][i];
        } else {
          st[j][i] = st[j - 1][i + l];
        }
      } else {
        st[j][i] = st[j - 1][i];
      }
    }
  }
  // [l, r)
  auto get_left_max_pos = [&] (int l, int r) -> int {
    int j = log2(r - l);
    int i0 = st[j][l], i1 = st[j][r - (1 << j)];
    if (x[i0] >= x[i1]) {
      return i0;
    } else {
      return i1;
    }
  };

  sort(kli.begin(), kli.end());
  ordered_set<pair<int, int>> os;
  string ans(m, '$');

  // [l, r)
  stack<pair<int, int>> ranges;
  ranges.emplace(make_pair(0, n));
  auto split = [&] (int m) -> void {
    auto [l, r] = ranges.top();
    ranges.pop();
    if (l != m) {
      ranges.emplace(l, m);
    }
    if (m + 1 != r) {
      ranges.emplace(m + 1, r);
    }
  };

  {
    int ii = 0;
    for (int k = 1; k <= n; ++k) {
      auto [l, r] = ranges.top();
      auto left_max_pos = get_left_max_pos(l, r);
      split(left_max_pos);
      os.insert(make_pair(left_max_pos, x[left_max_pos]));

      while (ii < m && get<0>(kli[ii]) == k) {
        ans[get<2>(kli[ii])] = os.find_by_order(get<1>(kli[ii]) - 1)->second;
        ++ii;
      }
    }
  }
  
  for (auto el : ans) {
    cout << el;
  }
  cout << "\n";

  return 0;
}
