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
  Unionfind(ll x) {
    node.resize(x);
    rep(i, 0, x)
        node[i] = i;
  }
  ll root(ll p) {
    if (node[p] == p) return p;
    return node[p] = root(node[p]);
  }
  void uni(ll a, ll b) {
    if (node[a] == node[b]) {
      return;
    }
    ll ra = root(a), rb = root(b);
    node[ra] = rb;
  }
};

int main() {
  cin >> N >> M;
  vll a(M), b(M);
  ll res = 0;
  rep(i, 0, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  rep(i, 0, M) {
    Unionfind uf(N);
    rep(j, 0, M) {
      if (i != j)
        uf.uni(a[j], b[j]);
    }
    ll c = 0;
    rep(j, 0, N) {
      if (uf.node[j] == j) c++;
    }
    if (c > 1) res++;
  }
  cout << res << endl;
  return 0;
}
