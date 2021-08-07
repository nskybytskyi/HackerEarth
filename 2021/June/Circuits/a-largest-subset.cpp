#include <bits/stdc++.h>
using namespace std;
vector<int> p;
void sieve(int n) {
  vector<int> ip(n, true);
  for (int d = 2; d * d < n; ++d) {
    if (ip[d]) {
      for (int m = d * d; m < n; m += d) {
        ip[m] = false;
      }
    }
  }
  for (int d = 2; d < n; ++d) {
    if (ip[d]) {
      p.push_back(d);
    }
  }
}
class DisjointSetUnion {
  public:
    explicit DisjointSetUnion(int size) : size_(size) {
      rank_.resize(size_);
      parent_.resize(size_);
      std::iota(parent_.begin(), parent_.end(), 0);
    }

    int Size() const {
      return size_;
    }

    int Find(int vertex) const {
      return (vertex == parent_[vertex]) ? \
        vertex : (parent_[vertex] = Find(parent_[vertex]));
    }

    void Union(int first, int second) {
      first = Find(first), second = Find(second);
      if (first != second) {
        --size_;
        if (rank_[first] < rank_[second]) {
          std::swap(first, second);
        }
        parent_[second] = first;
        if (rank_[first] == rank_[second]){
          ++rank_[first];
        }
      }
    }

  private:
    int size_;
    mutable std::vector<int> parent_;
    std::vector<int> rank_;
};

void solve () {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  unordered_map<int, int> pf;
  map<pair<int, int>, int> ppf;
  for (auto ai : a) {
    vector<int> pd;
    for (auto pi : p) {
      if (ai < pi) {
        break;
      }
      if (ai % pi == 0) {
        pd.push_back(pi);
        while (ai % pi == 0) {
          ai /= pi;
        }
      }
    }
    if (ai > 1) {
      pd.push_back(ai);
    }
    for (auto pi : pd) {
      ++pf[pi];
    }
    for (int pi : pd) {
      for (int pj : pd) {
        if (pi != pj) {
          ++ppf[{pi, pj}];
        }
      }
    }
  }
  int m = 0;
  vector<int> pp;
  for (auto [k, v] : pf) {
    if (m < v) {
      pp = {k};
      m = v;
    } else if (m == v) {
      pp.push_back(k);
    }
  }
  int k = pp.size();
  DisjointSetUnion dsu(k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      if (ppf[{pp[i], pp[j]}] == m) {
        dsu.Union(i, j);
      }
    }
  }
  vector<int> cs(k);
  for (int i = 0; i < k; ++i) {
    ++cs[dsu.Find(i)];
  }
  int r = 0;
  for (int i = 0; i < k; ++i) {
    r += (1 << cs[i]) - 1;
  }
  cout << m << " " << r << "\n";
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  sieve(31'624);
  int t; cin >> t; while (t--) solve();
  return 0;
}