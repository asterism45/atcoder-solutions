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
struct Edge {
  ll u;
  ll v;
  ll cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }

ll kruskal(vector<Edge> &eds) {
  ll sum = 0;
  Unionfind uf(V);
  sort(eds.begin(), eds.end(), comp_e);
  for (auto ed : eds) {
    if (!uf.same(ed.u, ed.v)) {
      sum += ed.cost;
      uf.unite(ed.u, ed.v);
    }
  }
  return sum;
}

int main() {
  cin >> V >> E;
  vector<Edge> eds(E);
  rep(i, 0, E) {
    ll u, v, co;
    cin >> u >> v >> co;
    Edge e = {u, v, co};
    eds[i] = e;
  }
  cout << kruskal(eds) << endl;
  return 0;
}
