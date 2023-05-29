#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define all(a) (a).begin(), (a).end()
using ll = long long;
using vll = vector<ll>;
using vc = vector<char>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
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
  cin >> H >> W;
  vvll X(H + 1, vll(W + 1)), S(H, vll(W));
  rep(i, 1, H + 1) {
    rep(j, 1, W + 1) {
      cin >> X[i][j];
    }
  }
  rep(i, 1, H + 1) {
    rep(j, 1, W + 1) {
      if (i == 1)
        X[i][j] += X[i][j - 1];
      else if (j == 1)
        X[i][j] += X[i - 1][j];
      else
        X[i][j] += (X[i - 1][j] + X[i][j - 1] - X[i - 1][j - 1]);
    }
  }
  cin >> Q;
  while (Q-- > 0) {
    cin >> A >> B >> C >> D;
    cout << X[C][D] - X[C][B - 1] - X[A - 1][D] + X[A - 1][B - 1] << endl;
  }

  return 0;
}