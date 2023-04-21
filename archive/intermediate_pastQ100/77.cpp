#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define pb push_back
#define mp make_pair
#define MOD 1000000
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
  vll dist(N - 1), a(M), s(N, 0);
  rep(i, 0, N - 1) cin >> dist[i];
  rep(i, 0, M) {
    cin >> a[i];
  }
  rep(i, 0, N - 1) {
    s[i + 1] = s[i] + dist[i];
  }
  ll cur = a[0], res = s[cur] % MOD;
  rep(i, 1, M) {
    ll nx = cur + a[i];
    res = res + abs(s[nx] - s[cur]) % MOD;
    cur = nx;
  }
  cout << res << endl;
  return 0;
}
