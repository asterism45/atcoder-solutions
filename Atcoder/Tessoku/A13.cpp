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

ll bs(const vll &A, const ll &left) {
  ll r = A.size(), l = left;
  ll mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (A[mid] - A[left] <= K)
      l = mid;
    else
      r = mid;
  }
  return l - left;
}

int main() {
  cin >> N >> K;
  vll A(N);
  rep(i, 0, N) cin >> A[i];
  ll res = 0;
  rep(i, 0, N)
      res += bs(A, i);
  cout << res << endl;
  return 0;
}