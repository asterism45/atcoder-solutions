#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define all(a) (a).begin(), (a).end()
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
  cin >> N;
  Unionfind uf(N);
  vll A(N);
  ll res = 0;
  rep(i, 0, N) {
    cin >> A[i];
    if (uf.same(i, --A[i])) {
      ll st = i;
      ll nx = A[i];
      res++;
      while (st != nx) {
        res++;
        nx = A[nx];
      }
    } else
      uf.unite(i, A[i]);
  }
  cout << res << endl;
  return 0;
}