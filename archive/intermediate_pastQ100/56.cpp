#include <bits/stdc++.h>
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

int main() {
  ll V, E, r;
  cin >> V >> E >> r;
  vector<vector<pair<ll, ll>>> G(V);
  rep(i, 0, E) {
    ll s, t, d;
    cin >> s >> t >> d;
    G[s].push_back(make_pair(d, t));
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vll dist(V, INF), flag(V, 0);
  pq.push(make_pair(0, r));
  dist[r] = 0;
  while (!pq.empty()) {
    pair<ll, ll> cu;
    cu = pq.top();
    pq.pop();
    flag[cu.second] = 1;
    // cout << cu.second << endl;

    rep(i, 0, G[cu.second].size()) {
      // cout << i << endl;
      if (flag[G[cu.second][i].second] == 0) {
        pq.push(make_pair(G[cu.second][i].first + dist[cu.second], G[cu.second][i].second));
        dist[G[cu.second][i].second] = min(dist[G[cu.second][i].second], dist[cu.second] + G[cu.second][i].first);
        // cout << "v:" << G[cu.second][i].second << ", d:" << dist[G[cu.second][i].second] << endl;
      }
    }
  }

  rep(i, 0, V) {
    // cout << "flag" << i << ":" << flag[i] << endl;
    if (dist[i] == INF)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }

  return 0;
}
