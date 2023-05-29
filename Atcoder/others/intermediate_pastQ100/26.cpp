#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
vector<bool> seen;
vll cnt;
void dfs(const vvll &G, ll v) {
  seen[v] = 1;
  for (auto nxt : G[v]) {
    if (seen[nxt] != 1) {
      cnt[nxt] += cnt[v];
      dfs(G, nxt);
    }
  }
}

int main() {
  cin >> N >> Q;
  vvll G(N + 1);
  rep(i, 0, N - 1) {
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cnt.assign(N + 1, 0);
  seen.assign(N + 1, 0);
  rep(i, 0, Q) {
    ll p, x;
    cin >> p >> x;
    cnt[p] += x;
  }
  dfs(G, 1);
  rep(i, 0, N) {
    cout << cnt[i + 1] << " ";
  }
  cout << endl;
  return 0;
}
