#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

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

int main() {
  ll n, q;
  cin >> n >> q;
  Unionfind uf(n);
  while (q-- > 0) {
    ll com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      uf.unite(x, y);
    } else if (com == 1) {
      cout << uf.same(x, y) << endl;
    }
  }
  return 0;
}