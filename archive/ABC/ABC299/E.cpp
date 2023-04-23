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
  rep(i, 0, M) {
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> K;
  if (K == 0) {
    cout << "Yes" << endl;
    vll seen(N + 1, 1);
    rep(i, 0, N) {
      cout << seen[i];
    }
    cout << endl;
    return 0;
  }
  vll p(K), d(K);
  rep(i, 0, K) {
    cin >> p[i] >> d[i];
  }
  vll seen(N + 1, -1);  // 1は黒,0は白
  rep(i, 0, K) {
    vll dist(N + 1, -1);
    queue<ll> que;
    dist[p[i]] = 0;
    if (d[i] == 0) {
      seen[p[i]] = 1;
    } else {
      seen[p[i]] = 0;
      dist[p[i]] = 0;
      que.push(p[i]);
    }
    while (!que.empty()) {
      ll v = que.front();
      que.pop();
      for (ll nv : G[v]) {
        if (dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        if (dist[nv] < d[i]) {
          seen[nv] = 0;
          que.push(nv);
        } else if (dist[nv] == d[i] && seen[nv] != 1)
          seen[nv] = 1;
        else {
          continue;
        }
      }
    }
  }
  bool f = true;
  rep(i, 0, K) {
    vll dist(N + 1, -1);
    queue<ll> que;
    bool whf = true, blf = false;
    dist[p[i]] = 0;
    if (d[i] == 0) {
      if (seen[p[i]] == 1)
        blf = true;
    } else {
      if (seen[p[i]] == 1) {
        whf = false;
      } else {
        dist[p[i]] = 0;
        que.push(p[i]);
      }
    }
    while (!que.empty()) {
      ll v = que.front();
      que.pop();
      for (ll nv : G[v]) {
        if (dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        if (dist[nv] < d[i]) {
          if (seen[nv] != 0) {
            whf = false;
          }
          que.push(nv);
        } else if (dist[nv] == d[i]) {
          if (seen[nv] == 1) {
            blf = true;
          }
        } else {
          continue;
        }
      }
    }
    if (!(whf && blf))
      f = false;
  }

  if (f) {
    cout << "Yes" << endl;
    rep(i, 1, N + 1) {
      if (seen[i] == -1)
        seen[i] = 1;
    }
    rep(i, 1, N + 1) {
      cout << seen[i];
    }
    cout << endl;
  } else
    cout << "No" << endl;

  return 0;
}
