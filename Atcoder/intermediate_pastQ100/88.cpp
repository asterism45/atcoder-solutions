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
  vll c(N);
  rep(i, 0, N) {
    cin >> c[i];
  }
  stack<pair<bool, ll>> st;
  st.push(mp(c[0], 1));
  rep(i, 1, N) {
    pair<bool, ll> pa = st.top();
    st.pop();
    if ((i + 1) % 2 == 1) {
      if (c[i] == pa.first) {
        pa.second++;
        st.push(pa);
      } else {
        st.push(pa);
        st.push(mp(c[i], 1));
      }
    } else {
      if (c[i] == pa.first) {
        pa.second++;
        st.push(pa);
      } else {
        pa.second++;
        pa.first = c[i];
        if (!st.empty()) {
          auto pa2 = st.top();
          st.pop();
          pa.second += pa2.second;
        }
        st.push(pa);
      }
    }
  }
  ll res = 0;
  while (!st.empty()) {
    auto pa = st.top();
    st.pop();
    if (pa.first == 0)
      res += pa.second;
  }
  cout << res << endl;
  return 0;
}