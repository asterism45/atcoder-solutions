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

int main() {
  cin >> Q;
  queue<string> que;
  string s;
  while (Q-- > 0) {
    cin >> A;
    switch (A) {
    case 1:

      cin >> s;
      que.push(s);
      break;
    case 2:
      cout << que.front() << endl;
      break;
    case 3:
      que.pop();
      break;
    default:
      break;
    }
  }

  return 0;
}