#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31))
#define pb push_back
#define mp make_pair
#define MOD 2147483647
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
void outputResult(bool flag) { cout << (flag ? "Yes" : "No") << endl; }

int main() {
  cin >> N >> Q;
  string s;
  cin >> s;

  vll H(N + 1, 0), pows(N + 1);
  ll m = 100;
  rep(i, 0, N) {
    ll p = s[i];
    H[i + 1] = (H[i] * m + p) % MOD;
  }
  pows[0] = 1;
  rep(i, 1, N + 1) {
    pows[i] = pows[i - 1] * m % MOD;
  }

  while (Q-- > 0) {
    cin >> A >> B >> C >> D;
    ll ha = H[B] - (H[A - 1] * pows[B - A + 1] % MOD);
    ll hb = H[D] - (H[C - 1] * pows[D - C + 1] % MOD);
    if (ha < 0) ha += MOD;
    if (hb < 0) hb += MOD;
    outputResult(ha == hb);
  }

  return 0;
}