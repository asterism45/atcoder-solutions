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
ll res = 0, cnt = 0;
ll dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  }
  else {
    return gcd(b, a % b);
  }
}

// distを返すパターン
void dijcstra(vector<vpll>& G, vll& dist) {
  pqueue pq;
  pq.emplace(mpa(0, 0));
  dist[0] = 0;
  while (!pq.empty()) {
    auto pa = pq.top();
    pq.pop();
    ll cu = pa.second;
    if (dist[cu] < pa.first) continue;
    for (auto [nxw, nx] : G[cu]) {
      if (dist[nx] <= dist[cu] + nxw) continue;
      dist[nx] = dist[cu] + nxw;
      pq.emplace(mpa(dist[nx], nx));
    }
  }
}

ll dijkstra(const vector<vector<pair<ll, ll>>>& G, ll r, ll p) {
  vll dist(N + 1, INF);
  pqueue pq;
  pq.push(mp(0, r));
  dist[r] = 0;
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    auto cu = top.second;
    visited[cu] = 1;
    if (dist[cu] < top.first) continue;
    for (auto [nxw, nx] : G[cu]) {
      if (visited[nx] == 0) {
        if (dist[nx] <= dist[cu] + nxw)
          continue;
        dist[nx] = dist[cu] + nxw;
        pq.push(mp(dist[nx], nx));
      }
    }
  }
  if (dist[p] == INF)
    return -1;
  else
    return dist[p];
}
int main() {
  ll n, k;
  cin >> n >> k;
  vector<vector<pair<ll, ll>>> G(n + 1);
  rep(i, 0, k) {
    ll mode;
    cin >> mode;
    ll a, b, d;
    switch (mode) {
    case 0:
      cin >> a >> b;
      cout << dijkstra(G, a, b, n) << endl;
      break;
    case 1:
      cin >> a >> b >> d;
      G[a].pb(mp(d, b));
      G[b].pb(mp(d, a));
    default:
      break;
    }
  }
  return 0;
}
