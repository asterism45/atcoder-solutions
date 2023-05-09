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
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void outputResult(bool flag) { cout << (flag ? "Yes" : "No") << endl; }

bool isOK(const vll &a, ll tim, ll key) {
  ll sums = 0;
  rep(i, 0, N)
      sums += (tim / a[i]);

  if (sums >= key)
    return true;
  else
    return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(const vll &a, ll key) {
  ll ng = -1;
  ll ok = 1000000000;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(a, mid, key))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main() {
  cin >> N >> K;
  vll A(N);
  rep(i, 0, N) cin >> A[i];
  cout << binary_search(A, K) << endl;

  return 0;
}