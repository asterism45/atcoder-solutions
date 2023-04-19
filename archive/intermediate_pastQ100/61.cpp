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

int main() {
  cin >> N >> M;
  vvll G(N, vll(N, INF));
  rep(i, 0, M) {
    ll a, b, t;
    cin >> a >> b >> t;
    G[--a][--b] = t;
    G[b][a] = t;
  }
  rep(i, 0, N)
      G[i][i] = 0;

  rep(k, 0, N) {
    rep(i, 0, N) {
      rep(j, 0, N)
          G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    }
  }

  ll res = INF;
  rep(i, 0, N) {
    ll ma = 0;
    rep(j, 0, N) {
      if (G[i][j] != INF)
        ma = max(ma, G[i][j]);
    }
    if (ma != 0)
      res = min(res, ma);
  }
  cout << res << endl;
  return 0;
}
