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
  cin >> N >> T;
  vll C(N), R(N);
  bool f = false;
  rep(i, 0, N) {
    cin >> C[i];
    if (C[i] == T) f = true;
  }
  ll res1 = -1, ma1 = -1, res2 = 1, ma2 = R[0];
  rep(i, 0, N) {
    cin >> R[i];
    if (f) {
      if (C[i] == T) {
        if (ma1 < R[i]) {
          res1 = i + 1;
          ma1 = R[i];
        }
      }
    } else {
      if (C[i] == C[0]) {
        if (ma2 < R[i]) {
          res2 = i + 1;
          ma2 = R[i];
        }
      }
    }
  }

  if (f) {
    cout << res1 << endl;
  } else {
    cout << res2 << endl;
  }

  return 0;
}
