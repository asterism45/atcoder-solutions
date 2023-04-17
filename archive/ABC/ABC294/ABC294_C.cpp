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
ll gcd(ll a, ll b)
{
  if (a % b == 0)
  {
    return b;
  }
  else
  {
    return gcd(b, a % b);
  }
}

int main()
{
  cin >> N >> M;
  vector<ll> A(N), B(M), ansa(N), ansb(M);

  rep(i,0,N)
    cin >> A[i];
  rep(i,0,M)
    cin >> B[i];
  
  ll a = 0, b = 0;
  rep(i,0,N+M){
    if(a == N){
      ansb[b] = i + 1;
      b++;
    }
    else if(b == M){
      ansa[a] = i + 1;
      a++;
    }
    else if(A[a] < B[b]){
      ansa[a] = i + 1;
      a++;
    }
    else{
      ansb[b] = i + 1;
      b++;
    }
  }
  rep(i,0,N)
    cout << ansa[i] << " ";
  cout << endl;
  rep(i,0,M)
    cout << ansb[i] << " ";
  cout << endl;

  return 0;
}
