#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<tuple<int, int, int, string>> qs(q);
    unordered_set<int64_t> willask;
    for (auto& [tp, l, r, u] : qs) {
        cin >> tp >> l >> r >> u;
        --l, --r, --tp;
        if (!tp) {
            int64_t h = 0;
            for (auto ui : u) {
                h = (h << 5) | (ui - 'a' + 1);
            }
            willask.insert(h);
        }
    }
    unordered_map<int64_t, ordered_set<int>> pos;
    for (int len = 1; len <= 10; ++len) {
        int64_t h = 0;
        for (int i = 0; i < len; ++i) {
            h = (h << 5) | (s[i] - 'a' + 1);
        }
        const int64_t H = (1ll << (5 * len)) - 1;
        for (int start = 0; start + len <= n; ++start) {
            if (willask.count(h)) {
                pos[h].insert(start);
            }
            h = ((h << 5) | (s[start + len] - 'a' + 1)) & H;
        }
    }
    for (auto& [tp, l, r, u] : qs) {
        if (!tp) {
            const int len = u.length();
            int64_t h = 0;
            for (auto ui : u) {
                h = (h << 5) | (ui - 'a' + 1);
            }
            cout << pos[h].order_of_key(r - len + 2) - pos[h].order_of_key(l) << "\n";
        } else {
            for (int len = 1; len <= 10; ++len) {
                int64_t h = 0;
                const int S = max(0, l - len + 1);
                for (int i = S; i < S + len; ++i) {
                    h = (h <<= 5) | (s[i] - 'a' + 1);
                }
                const int64_t H = (1ll << (5 * len)) - 1;
                for (int start = S; start <= min(r, n - len); ++start) {
                    if (willask.count(h)) {
                        pos[h].erase(start);
                    }
                    h = ((h << 5) | (s[start + len] - 'a' + 1)) & H;
                }
            }
            for (int i = 0; i <= r - l; ++i) {
                s[l + i] = u[i];
            }
            for (int len = 1; len <= 10; ++len) {
                int64_t h = 0;
                const int S = max(0, l - len + 1);
                for (int i = S; i < S + len; ++i) {
                    h = (h << 5) | (s[i] - 'a' + 1);
                }
                const int64_t H = (1ll << (5 * len)) - 1;
                for (int start = S; start <= min(r, n - len); ++start) {
                    if (willask.count(h)) {
                        pos[h].insert(start);
                    }
                    h = ((h << 5) | (s[start + len] - 'a' + 1)) & H;
                }
            }
        }
    }
    return 0;
}
