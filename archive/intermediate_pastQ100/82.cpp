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
  while (1) {
    cin >> N;
    if (N == 0) return 0;
    vll tim(86400, 0);
    rep(i, 0, N) {
      vll da(2, 0);
      rep(i, 0, 2) {
        string s;
        cin >> s;
        ll h, m, c;
        if (s[0] != 0) {
          h = ((s[0] - '0') * 10 + (s[1] - '0')) * 3600;
        } else {
          h = (s[1] - '0') * 3600;
        }
        if (s[3] != 0) {
          m = ((s[3] - '0') * 10 + (s[4] - '0')) * 60;
        } else {
          m = (s[4] - '0') * 60;
        }
        if (s[6] != 0) {
          c = ((s[6] - '0') * 10 + (s[7] - '0'));
        } else {
          c = (s[7] - '0');
        }
        da[i] += (h + m + c);
      }
      tim[da[0]]++;
      tim[da[1]]--;
    }
    ll res = tim[0];
    rep(i, 1, tim.size()) {
      tim[i] += tim[i - 1];
      res = max(res, tim[i]);
    }
    cout << res << endl;
  }
  return 0;
}
