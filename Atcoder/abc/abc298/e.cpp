#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i >= (r); i--)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define pb push_back
#define mp make_pair
#define MOD 998244353
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
ll modpow(ll x) {
  ll ret = 1, n = MOD - 2;
  while (n > 0) {
    if (x & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}
int main() {
  cin >> N >> A >> B >> P >> Q;
  vector<vector<vector<ll>>> dp(N + 1 + P, vvll(N + 1 + Q, vll(2, -1)));
  for (int i = 0; i < N; i++)
    for (int f = 0; f < 2; f++) {
      dp[N][i][f] = 1;
      dp[i][N][f] = 0;
    }
  rep(i, N - 1, 0) {
    rep(j, N - 1, 0) {
      ll retp = 1, retq = 1;
      for (ll a = 1; a < P + 1; a++) {
        retp = (retp + dp[min(i + a, N)][j][0]) % MOD;
        if (retp < 0) retp += MOD;
      }
      for (ll b = 1; b < Q + 1; b++) {
        retq = (retq + dp[i][min(j + b, N)][1]) % MOD;
        if (retq < 0) retq += MOD;
      }
      dp[i][j][1] = retp * modpow(P) % MOD;
      dp[i][j][0] = retq * modpow(Q) % MOD;
    }
  }

  cout << dp[A][B][1] << endl;

  return 0;
}
