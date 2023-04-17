#include <math.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res, cnt = 0;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  cin >> N >> X;
  vector<ll> a(N);
  set<ll> A;
  rep(i, 0, N) {
    cin >> a[i];
    A.insert(a[i]);
  }
  bool flag = false;
  rep(i, 0, N) {
    ll num = a[i] + X;
    if (find(A.find(num)) != A.end()) {
      flag = true;
    }
    if (flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }
