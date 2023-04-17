#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res, cnt = 0;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
vll seen;
bool dfs(vvll G, ll v, ll t) {
  seen[v] = 1;
  for (auto next : G[v]) {
    if (seen[next])
      continue;
    if (next == t)
      return 1;
    if (dfs(G, next, t))
      return 1;
  }
  return 0;
}

int main() {
  return 0;
}
