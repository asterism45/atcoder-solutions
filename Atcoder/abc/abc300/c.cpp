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
ll A, B, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
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
  vector<vector<char>> C(H, vector<char>(W));
  ll m = min(H, W);
  vll S(m, 0);
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> C[i][j];
    }
  }

  rep(i, 0, H - 1) {
    rep(j, 0, W - 1) {
      if (C[i][j] == '#' && C[i + 1][j + 1] == '#') {
        C[i][j] = '.';
        C[i + 1][j + 1] = '.';
        ll f = 1, p = i + 2, q = j + 2, cnt = 2;
        while (f) {
          if (p < H && q < W && C[p][q] == '#') {
            C[p][q] = '.';
            cnt++;
            p++;
            q++;
          } else
            f = 0;
        }
        S[(cnt - 3) / 2]++;
      }
    }
  }
  rep(i, 0, S.size()) {
    if (i != S.size() - 1)
      cout << S[i] << " ";
    else
      cout << S[i];
  }
  cout << endl;
  return 0;
}