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
ll dy[2] = {1, 0}, dx[2] = {0, 1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
ll dist = INF;
void deletewall(vector<vector<char>> &s, ll y, ll x) {
  s[y][x] = '.';
  rep(i, 0, 2) {
    ll ny = y + dy[i], nx = x + dx[i];
    if (ny < H && nx < W && s[ny][nx] == '#') {
      deletewall(s, ny, nx);
    }
  }
}

void dfs(vector<vector<char>> &s, ll y, ll x, ll cnt) {
  vector<vector<char>> ns = s;
  if (s[y][x] != '.') {
    deletewall(ns, y, x);
    cnt++;
    if (dist < cnt) return;
  }
  if (y == H - 1 && x == W - 1) {
    dist = min(dist, cnt);
    return;
  }
  rep(i, 0, 2) {
    ll ny = y + dy[i], nx = x + dx[i];
    if (ny < H && nx < W) {
      dfs(s, ny, nx, cnt);
    }
  }
}

int main() {
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> s[i][j];
    }
  }
  dfs(s, 0, 0, 0);
  ll res = dist;
  cout << res << endl;

  return 0;
}