class Unionfind {
 public:
  vll node;
  Unionfind(ll n) {
    node.resize(n);
    rep(i, 0, n)
        node[i] = i;
  }
  ll root(ll p) {
    if (node[p] == p) return p;
    return node[p] = root(node[p]);
  }
  void unite(ll x, ll y) {
    if (root(x) == root(y)) return;
    ll rx = root(x), ry = root(y);
    node[rx] = ry;
  }
  bool same(ll x, ll y) {
    if (root(x) == root(y))
      return true;
    else
      return false;
  }
};