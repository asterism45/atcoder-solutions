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

int main() {
  cin >> N >> M >> X;
  vll c(N);
  vvll a(N, vll(M));
  rep(i, 0, N) {
    cin >> c[i];
    rep(j, 0, M) {
      cin >> a[i][j];
    }
  }
  ll res = INF;

  for (ll bit = 0; bit < (1 << N); ++bit) {
    vll S;
    for (ll i = 0; i < N; ++i) {
      if (bit & (1 << i))
        S.push_back(i);
    }
    ll sum = 0;
    vll alg(M, 0);
    rep(i, 0, S.size()) {
      ll num = S[i];
      rep(i, 0, M) {
        alg[i] += a[num][i];
      }
      sum += c[num];
    }
    ll flag = true;
    rep(i, 0, M) {
      if (alg[i] < X)
        flag = false;
    }
    if (flag)
      res = min(res, sum);
  }

  if (res == INF)
    cout << -1 << endl;
  else
    cout << res << endl;

  return 0;
}