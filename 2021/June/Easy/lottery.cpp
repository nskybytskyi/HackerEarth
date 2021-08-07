#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> parent, sz, mx;
  int64_t profit = 0;
  DSU(int size) {
    parent.resize(size);
    sz.resize(size, 1);
    mx.resize(size);
    iota(parent.begin(), parent.end(), 0);
  }
  int Find(int vertex) {
    return vertex == parent[vertex] ? vertex : parent[vertex] = Find(parent[vertex]);
  }
  bool Union(int row, int col, int coin_value) {
    row = Find(row);
    col = Find(col);
    if (row == col) {
      if (!mx[row]) {
        profit += coin_value;
      }
      mx[row] = max(mx[row], coin_value);
      return false;
    }
    if (sz[row] < sz[col]) {
      swap(row, col);
    }
    if (mx[row] < mx[col]) {
      swap(mx[row], mx[col]);
    }
    if (!mx[col]) {
      profit += coin_value;
    }
    return parent[col] = row, sz[row] += sz[col], true;
  }
};

int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int coins_count, rows, cols;
    cin >> coins_count >> rows >> cols;
    DSU dsu(rows + cols);
    vector<tuple<int, int, int>> coins(coins_count);
    for (auto& [row, col, coin_value] : coins) {
      cin >> row >> col >> coin_value;
      --row;
      --col;
    }
    sort(coins.begin(), coins.end(), [] (const auto& first_coin, const auto& second_coin) -> bool {
      return get<2>(first_coin) >= get<2>(second_coin); });
    for (auto [row, col, coin_value] : coins) {
      dsu.Union(row, col + rows, coin_value);
    }
    cout << dsu.profit << '\n';
  }
  return 0;
}