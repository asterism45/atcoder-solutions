#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
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

int main() {
  cin >> Q;
  queue<ll> S;
  S.push(1);
  ll res = 1;
  rep(q, 0, Q) {
    ll mode;
    cin >> mode;
    if (mode == 1) {
      ll x;
      cin >> x;
      S.push(x);
      res = (res * 10 + x) % MOD;
    } else if (mode == 2) {
      ll ret = 1, n = S.size() - 1, x = 10;
      while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
      }
      res = (res - (S.front() * ret)) % MOD;
      if (res < 0) res += MOD;
      S.pop();
    } else if (mode == 3) {
      cout << res << endl;
    }
  }
  return 0;
}
