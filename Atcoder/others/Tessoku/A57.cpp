#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31))
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
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void outp(bool flag) { cout << (flag ? "Yes" : "No") << endl; }

int main() {
  cin >> N >> Q;
  vll A(N + 1);
  vvll dp(N + 1, vll(32, -1));
  rep(i, 1, N + 1) {
    cin >> A[i];
    dp[i][0] = A[i];
  }

  rep(j, 1, 32) {
    rep(i, 1, N + 1) {
      dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
  }
  while (Q-- > 0) {
    cin >> X >> Y;
    ll res = X;
    for (ll i = 31; i >= 0; i--) {
      if ((Y / (1 << i)) % 2 == 1)
        res = dp[res][i];
    }
    cout << res << endl;
  }

  return 0;
}