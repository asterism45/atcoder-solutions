// mapに変更予定
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
ll modinv(ll x) {
  ll ret = 1, n = MOD - 2;
  while (n > 0) {
    if (n & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}
ll modpowinv(ll x, ll n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return modinv(ret);
}

void dfs(const vvll &tree, ll v, ll pa, vll &subtree_size) {
  for (auto nv : tree[v]) {
    if (nv != pa)
      dfs(tree, nv, v, subtree_size);
  }
  subtree_size[v] = 1;
  for (auto nv : tree[v]) {
    if (nv == pa) continue;
    subtree_size[v] += subtree_size[nv];
  }
  // cout << "v:" << v << "sub:" << subtree_size[v] << endl;
}

int main() {
  cin >> N;
  vvll tree(N);
  vll subtree_size(N);
  rep(i, 0, N - 1) {
    ll a, b;
    cin >> a >> b;
    tree[--a].push_back(--b);
    tree[b].push_back(a);
  }
  dfs(tree, 0, -1, subtree_size);
  ll res = 0;
  vll powmemo(N + 1, -1);
  // cout << "N:" << N << endl;
  rep(i, 0, N) {
    multiset<ll> s;
    for (auto nv : tree[i]) {
      s.insert(subtree_size[nv]);
    }
    if (s.size() < 2) continue;
    if (i != 0) {
      s.erase(--s.end());
      s.insert(N - subtree_size[i]);
    }
    ll p_0 = 1, p1 = 0;
    for (auto p : s) {
      // cout << "p" << p << endl;
      if (powmemo[p] == -1)
        powmemo[p] = modpowinv(2, p);
      p_0 = p_0 * powmemo[p] % MOD;
    }
    for (auto it = s.begin(); it != s.end(); ++it) {
      ll tmp = 1;
      for (auto it2 = s.begin(); it2 != s.end(); ++it2) {
        if (powmemo[*it2] == -1)
          powmemo[*it2] = modpowinv(2, *it2);
        if (it != it2)
          tmp = tmp * powmemo[*it2] % MOD;
        else {
          ll exc = 1 - modpowinv(2, *it2);
          if (exc < 0) exc += MOD;
          tmp = tmp * exc % MOD;
        }
      }
      p1 = (p1 + tmp) % MOD;
    }
    ll ret = 1 - p_0;
    if (ret < 0) ret += MOD;
    ret -= p1;
    if (ret < 0) ret += MOD;
    if (powmemo[1] == -1)
      powmemo[1] = modpowinv(2, 1);
    ret = ret * powmemo[1];
    // cout << ret << endl;
    res = (res + ret) % MOD;
  }
  cout << res << endl;
  return 0;
}