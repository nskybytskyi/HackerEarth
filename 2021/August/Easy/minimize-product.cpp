#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'00'7;
const int kInfinity = numeric_limits<int>::max();
struct T {
  int m1, c1, m2, c2;
  T() : m1(kInfinity), c1(0), m2(kInfinity), c2(0) { }
  T(int ai) : m1(ai), c1(1), m2(kInfinity), c2(0) { }
  T(int m1, int c1, int m2, int c2) : m1(m1), c1(c1), m2(m2), c2(c2) { }
};
T Combine(T l, T r) {
  if (l.m1 > r.m1) {
    swap(l, r);
  }
  if (l.m1 < r.m1) {
    int m1 = l.m1;
    int c1 = l.c1;
    if (l.m2 < r.m1) {
      return T(m1, c1, l.m2, l.c2);
    } else if (l.m2 > r.m1) {
      return T(m1, c1, r.m1, r.c1);
    } else {  // l.m2 == r.m1
      return T(m1, c1, l.m2, l.c2 + r.c1);
    }
  } else {  // l.m1 == r.m1
    int m1 = l.m1;
    int c1 = l.c1 + r.c1;
    if (l.m2 < r.m2) {
      return T(m1, c1, l.m2, l.c2);
    } else if (l.m2 > r.m2) {
      return T(m1, c1, r.m2, r.c2);
    } else {  // l.m2 == r.m2
      return T(m1, c1, l.m2, l.c2 + r.c2);
    }
  }
}
struct SegmentTree {
  int sz;
  vector<T> tree;
  SegmentTree(int sz) : sz(sz) {
    tree.resize(sz << 2);
  }
  void Initialize(vector<int>& a) {
    Initialize(1, 0, sz - 1, a);
  }
  void Update(int x, int v) {
    Update(1, 0, sz - 1, x, v);
  }
  T Query(int l, int r) {
    return Query(1, 0, sz - 1, l, r);
  }
  void Initialize(int tv, int tl, int tr, vector<int>& a) {
    if (tl == tr) {
      tree[tv] = T(a[tl]);
    } else {
      int tm = (tl + tr) / 2;
      Initialize(2 * tv, tl, tm, a);
      Initialize(2 * tv + 1, tm + 1, tr, a);
      tree[tv] = Combine(tree[2 * tv], tree[2 * tv + 1]);
    }
  }
  void Update(int tv, int tl, int tr, int x, int v) {
    if (tl == tr) {
      tree[tv] = T(v);
    } else {
      int tm = (tl + tr) / 2;
      if (x <= tm) {
        Update(2 * tv, tl, tm, x, v);
      } else {
        Update(2 * tv + 1, tm + 1, tr, x, v);
      }
      tree[tv] = Combine(tree[2 * tv], tree[2 * tv + 1]);
    }
  }
  T Query(int tv, int tl, int tr, int l, int r) {
    if (l > r) {
      return T();
    } else if (tl == l && tr == r) {
      return tree[tv];
    } else {
      int tm = (tl + tr) / 2;
      return Combine(Query(2 * tv, tl, tm, l, min(r, tm)),
                     Query(2 * tv + 1, tm + 1, tr, max(l, tm + 1), r));
    }
  }
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);
    vector<int> a(n);
    for (auto& ai : a) {
      cin >> ai;
    }
    st.Initialize(a);
    int64_t sum = 0;
    while (q--) {
      int tp;
      cin >> tp;
      if (tp == 1) {
        int x, v;
        cin >> x >> v;
        --x;
        st.Update(x, v);
      } else {  // tp == 2
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto ans = st.Query(l, r);
        if (ans.c1 > 1) {
          sum += (ans.c1 * 1ll * (ans.c1 - 1)) / 2;
        } else {
          sum += ans.c2;
        }
      }
    }
    cout << sum % mod << "\n";
  }
  return 0;
}