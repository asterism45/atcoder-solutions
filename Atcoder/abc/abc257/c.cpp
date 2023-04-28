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
  vll W(N);
  set<ll> man, child;
  rep(i, 0, N) {
    cin >> W[i];
    if (S[i])
      man.insert(W[i]);
    else
      child.insert(W[i]);
  }
  ll res = N;
  if (man.empty() || child.empty()) {
    cout << N << endl;
    return 0;
  }
  while (*--child.end() >= *man.begin()) {
  }
  cout << res << endl;
  return 0;
}