#include <bits/stdc++.h>
using namespace std;

struct TreeEntry {
  int left_value, left_length, right_value, right_legth, length; int64_t best_value;
  TreeEntry() : left_value(0), left_length(0), right_value(0), right_legth(0), best_value(0), length(0) { }
  TreeEntry(int value) : left_value(value), left_length(1), right_value(value), right_legth(1), best_value(value), length(1) { }
};

inline int64_t Function(int64_t value, int64_t length) {
  length = min(length, value);
  return (length * (2 * value - length + 1)) / 2;
}

TreeEntry Combine(const TreeEntry& left, const TreeEntry& right) {
  TreeEntry combined;

  combined.length = left.length + right.length;

  combined.left_value = left.left_value;
  if (left.left_length == left.length && right.left_value == left.left_value) {
    combined.left_length = left.length + right.left_length;
  } else {
    combined.left_length = left.left_length;
  }

  combined.right_value = right.right_value;
  if (right.right_legth == right.length && left.right_value == right.right_value) {
    combined.right_legth = right.length + left.right_legth;
  } else {
    combined.right_legth = right.right_legth;
  }

  combined.best_value = max(left.best_value, right.best_value);

  if (left.right_value == right.left_value) {
    combined.best_value = max(combined.best_value, Function(left.right_value, left.right_legth + right.left_length));
  }

  return combined;
}

class SegmentTree {
  public:
    SegmentTree(int size) : size_(size) {
      tree_.resize(size_ << 2);
    }

    void Initialize(const vector<int>& array) {
      Initialize_(array, 1, 0, size_ - 1);
    }

    TreeEntry Range(int left, int right) {
      return Range_(left, right, 1, 0, size_ - 1);
    }

    void Point(int index, int value) {
      Point_(index, value, 1, 0, size_ - 1);
    }

  private:
    int size_;
    vector<TreeEntry> tree_;

    void Initialize_(const vector<int>& array, int vertex, int tree_left, int tree_right) {
      if (tree_left == tree_right) {
        tree_[vertex] = array[tree_left];
      } else {
        int tree_middle = (tree_left + tree_right) >> 1;
        Initialize_(array, vertex << 1, tree_left, tree_middle);
        Initialize_(array, (vertex << 1) | 1, tree_middle + 1, tree_right);
        tree_[vertex] = Combine(tree_[vertex << 1], tree_[(vertex << 1) | 1]);
      }
    }

    TreeEntry Range_(int left, int right, int vertex, int tree_left, int tree_right) {
      if (left > right) {
        return 0;
      } else if (left == tree_left && right == tree_right) {
        return tree_[vertex];
      } else {
        int tree_middle = (tree_left + tree_right) >> 1;
        return Combine(Range_(left, min(right, tree_middle), vertex << 1, tree_left, tree_middle),
                       Range_(max(left, tree_middle + 1), right, (vertex << 1) | 1, tree_middle + 1, tree_right));
      }
    }

    void Point_(int index, int value, int vertex, int tree_left, int tree_right) {
      if (tree_left == tree_right) {
        tree_[vertex] = value;
      } else {
        int tree_middle = (tree_left + tree_right) >> 1;
        if (index <= tree_middle) {
          Point_(index, value, vertex << 1, tree_left, tree_middle);
        } else {
          Point_(index, value, (vertex << 1) | 1, tree_middle + 1, tree_right);
        }
        tree_[vertex] = Combine(tree_[vertex << 1], tree_[(vertex << 1) | 1]);
      }
    }
};

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }

  SegmentTree segment_tree(n);
  segment_tree.Initialize(a);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      cout << segment_tree.Range(l - 1, r - 1).best_value << " ";
    } else {  // t == 2
      int x, v;
      cin >> x >> v;
      segment_tree.Point(x - 1, v);
    }
  }
  cout << "\n";

  return 0;
}