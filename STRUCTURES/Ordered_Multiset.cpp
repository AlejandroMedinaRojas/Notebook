#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <class T>
struct OrderedMultiset {
  OrderedSet<pair<T, int>> ordered_set;
  map<T, int> mp;
  
  void insert(T x) {
    ordered_set.insert({x, ++mp[x]});
  }
  void erase(T x) {
    ordered_set.erase({x, --mp[x]});
  }
  int order_of_key(T x) {
    return ordered_set.order_of_key({x, 0});
  }
  T find_by_order(int idx) {
    return (*ordered_set.find_by_order(idx)).first;
  }
  int count(T x) {
    return mp[x];
  }
  
  int size() { return (int)ordered_set.size(); }
  bool empty() { return ordered_set.empty(); }
  void clear() { ordered_set.clear(); mp.clear()}
};

// OrderedMultiset
// Time complexity O(log n)
// Space complexity O(n)