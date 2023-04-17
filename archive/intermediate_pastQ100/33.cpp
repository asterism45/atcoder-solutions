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
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> s[i][j];
      if (s[i][j] == '.')
        cnt++;
    }
  }
  vvll dist(H, vll(W, -1));
  queue<pair<ll, ll>> que;
  dist[0][0] = 0;
  que.push(make_pair(0, 0));
  while (!que.empty()) {
    pair<ll, ll> pa = que.front();
    que.pop();
    rep(i, 0, 4) {
      ll ny = pa.first + dy[i], nx = pa.second + dx[i];
      if (0 <= ny && ny < H && 0 <= nx && nx < W && s[ny][nx] == '.' && dist[ny][nx] == -1) {
        dist[ny][nx] = dist[pa.first][pa.second] + 1;
        que.push(make_pair(ny, nx));
      }
    }
  }

  if (dist[H - 1][W - 1] == -1)
    cout << -1 << endl;
  else
    cout << (cnt - dist[H - 1][W - 1]) - 1 << endl;

  return 0;
}
