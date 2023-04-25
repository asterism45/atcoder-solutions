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
#define INF ((1LL << 62) - (1LL << 61)) /*オーバーフローしない程度に大きい数*/
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
  cin >> N;
  vector<double> x(N);
  rep(i, 0, N)
  {
    cin >> x[i];
  }

  if(N >= 6){
    rep(i,0,N)
      x[i] = 1 / x[i];
  }

  double ansmin = INF, ansmax = -INF;

  if (N < 6)
  {
    rep(i,0,N-2){
      rep(j,i+1,N-1){
        rep(k,j+1,N){
          double value = (x[i] + x[j] + x[k]) / (x[i] * x[j] * x[k]);
          //cout << i << ":" << value << endl;
          ansmin = min(ansmin, value);
          ansmax = max(ansmax, value);
        }
      }
    }
  }
  else
  {
    sort(x.begin(), x.end());
    vector<double> pck(6);
    rep(i, 0, 3)
    {
      pck[i] = x[i];
      pck[5 - i] = x[N - 1 - i];
    }

    rep(i, 0, 6)
        pck[i] = 1 / pck[i];

    rep(i, 0, 4)
    {
      rep(j, i + 1, 5)
      {
        rep(k, j + 1, 6)
        {
          double value = (pck[i] + pck[j] + pck[k]) / (pck[i] * pck[j] * pck[k]);
          // cout << i << ":" << j << ":" << k << ":" << value << endl;
          ansmin = min(ansmin, value);
          ansmax = max(ansmax, value);
        }
      }
    }
  }

  cout << ansmin << endl;
  cout << ansmax << endl;

  return 0;
}
