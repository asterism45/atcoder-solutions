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
  cin >> N >> Q;
  vector<multiset<ll>> box(300000);
  vector<set<ll>> nums(300000);
  rep(q, 0, Q) {
    ll mode;
    cin >> mode;
    if (mode == 1) {
      ll i, j;
      cin >> i >> j;
      box[j].insert(i);
      nums[i].insert(j);
    } else if (mode == 2) {
      ll i;
      cin >> i;
      for (auto num : box[i]) {
        cout << num << " ";
      }
      cout << endl;
    } else if (mode == 3) {
      ll i;
      cin >> i;
      for (auto num : nums[i]) {
        cout << num << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
