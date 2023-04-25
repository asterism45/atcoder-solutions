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
  cin >> N;
  string S;
  cin >> S;
  ll cnt = 0;
  bool f = false;
  ll res = -1;
  rep(i, 0, N) {
    if (!f && S[i] == 'o') {
      f = true;
      cnt = 1;
      continue;
    }
    if (f && S[i] == 'o') {
      cnt++;
      continue;
    }
    if (f && S[i] != 'o') {
      res = max(res, cnt);
      f = false;
      cnt = 0;
    }
  }
  if (f) {
    if (cnt != N) {
      res = max(res, cnt);
    }
  }
  cout << res << endl;
  return 0;
}
