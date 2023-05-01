#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <math.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res, cnt = 0;
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
  cin >> N >> X;
  vector<ll> A(N), B(N);
  rep(i, 0, N)
          cin >>
      A[i];
  bool flag = false;

  rep(i, 0, N)
  {
    B[i] = A[i] + X;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  ll numa = 0, numb = 0;
  while (numa != N || numb != N)
  {
    if (numa == N)
    {
      if (A[numa - 1] == B[numb])
      {
        flag = true;
        break;
      }
      else
        numb++;
    }
    else if (numb == N){
      if (A[numa] == B[numb - 1])
      {
        flag = true;
        break;
      }
      else
        numa++;
    }
    else if (A[numa] == B[numb])
    {
      flag = true;
      break;
    }
    else if (A[numa] > B[numb])
      numb++;
    else
      numa++;
  }

  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
