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
ll dy[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

void dfs(const vvll &c, vvll &seen, ll x, ll y) {
  seen[y][x] = 1;
  rep(i, 0, 8) {
    ll nx = x + dx[i], ny = y + dy[i];
    if (0 <= nx && nx < W && 0 <= ny && ny < H && !seen[ny][nx] && c[ny][nx])
      dfs(c, seen, nx, ny);
  }
}

int main() {
  while (1) {
    cin >> W >> H;
    if (W == 0)
      return 0;
    vvll c(H, vll(W)), seen(H, vll(W, 0));
    ll cnt = 0;
    rep(i, 0, H) {
      rep(j, 0, W) {
        cin >> c[i][j];
      }
    }
    rep(i, 0, H) {
      rep(j, 0, W) {
        if (c[i][j] == 1 && !seen[i][j]) {
          dfs(c, seen, j, i);
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
