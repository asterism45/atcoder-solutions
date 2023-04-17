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
  vvll G(N + 1);
  vll dig(N + 1, 0);
  rep(i, 0, M) {
    ll a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    G[a].push_back(c);
    G[c].push_back(a);
    dig[a]++;
    dig[c]++;
  }
  vll seen(N + 1, 0);
  ll cntc = 0, cnt = 0;
  rep(i, 1, N + 1) {
    if (seen[i])
      continue;
    bool f = true;
    queue<ll> q;
    q.push(i);
    while (!q.empty()) {
      ll v = q.front();
      q.pop();
      seen[v] = 1;
      if (dig[v] != 2)
        f = false;
      for (auto nv : G[v]) {
        if (!seen[nv])
          q.push(nv);
      }
    }
    if (f)
      cntc++;
    else
      cnt++;
  }

  cout << cntc << " " << cnt << endl;

  return 0;
}
