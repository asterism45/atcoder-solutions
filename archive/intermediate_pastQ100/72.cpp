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

ll modpow(ll x) {
  ll ret = 1;
  rep(i, 1, x + 1) {
    ret = ret * i % MOD;
  }
  return ret;
}

ll modinv(ll x) {
  ll ret = 1, n = MOD - 2;
  while (n > 0) {
    if (n & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}
ll modpowinv(ll x) {
  ll ret = 1;
  rep(i, 1, x + 1) {
    ret = ret * modinv(i) % MOD;
  }
  return ret;
}
int main() {
  cin >> W >> H;
  ll res = modpow(W + H - 2) * modpowinv(H - 1) % MOD * modpowinv(W - 1) % MOD;
  cout << res << endl;
  cout << res;
  return 0;
}
