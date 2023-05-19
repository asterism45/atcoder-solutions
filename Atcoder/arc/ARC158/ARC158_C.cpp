#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <math.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, J, K, L, M, N, P, Q, S, T, U, X, Y, Z;
ll ans;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

bool isOK(ll index, ll key){
}

int main()
{
  cin >> N;
  vector<ll> A(N), value(N);
  ll sum = 0, count = 0;

  rep(i,0,N)
    cin >> A[i];
  sort(A.begin(), A.end());
  
  rep(i,0,N){
    ll tmp = A[i];
    do
    {
      sum += tmp % 10;
    } while ((tmp /= 10) != 0);
  }

  sum *= 2 * N;
  ll k = 16;

  rep(i,1,k){
    rep(i,0,n){
      value[i] = A[i] % (ll)(pow(10, k));
    }
  }

  return 0;
}
