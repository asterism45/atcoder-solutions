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
  Unionfind uf(2 * N);
  sort(eds.begin(), eds.end(), comp_e);
  for (auto ed : eds) {
    if (!uf.same(ed.u, ed.v)) {
      sum += ed.cost;
      uf.unite(ed.u, ed.v);
    }
  }
  return sum;
}
struct Cordinate {
  ll num;
  ll x;
  ll y;
};
bool comp_x(const Cordinate &e1, const Cordinate &e2) { return e1.x < e2.x; }
bool comp_y(const Cordinate &e1, const Cordinate &e2) { return e1.y < e2.y; }

int main() {
  cin >> N;
  vector<Cordinate> cors(N);
  vector<Edge> edges(2 * N);
  rep(i, 0, N) {
    ll n = i, x, y;
    cin >> x >> y;
    cors[i] = {n, x, y};
  }
  sort(cors.begin(), cors.end(), comp_x);
  rep(i, 1, N) {
    ll u = cors[i - 1].num, v = cors[i].num, co = abs(cors[i - 1].x - cors[i].x);
    Edge e = {u, v, co};
    edges.push_back(e);
  }
  sort(cors.begin(), cors.end(), comp_y);
  rep(i, 1, N) {
    ll u = cors[i - 1].num, v = cors[i].num, co = abs(cors[i - 1].y - cors[i].y);
    Edge e = {u, v, co};
    edges.push_back(e);
  }
  cout << kruskal(edges);
  return 0;
}
