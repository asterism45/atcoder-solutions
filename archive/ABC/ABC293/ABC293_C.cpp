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
using ll = long long;
ll B, C, D, F, G, J, K, L, M, N, P, Q, S, T, U, X, Y, Z;
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
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i,0,H){
    rep(j,0,W)
      cin >> A[i][j];
  }
  ll tmp[1000];
  ll count = 0;

  rep(i, 0, H - 1)
      tmp[i] = 0;
  rep(i, H - 1, W + H - 2)
      tmp[i] = 1;

  do
  {
    vector<ll> value(100, -1);
    value.push_back(A[0][0]);
    bool flag = false;
    ll x = 0, y = 0;
    rep(i,0,H+W - 2){
      switch (tmp[i])
      {
      case 0:
        y++;
        if(find(value.begin(), value.end(), A[y][x]) != value.end()){
          flag = true;
          break;
        }
        else
          value.push_back(A[y][x]);
        break;
      case 1:
        x++;
        if(find(value.begin(), value.end(), A[y][x]) != value.end()){
          flag = true;
          break;
        }
        else
          value.push_back(A[y][x]);
        break;
      
      default:
        break;
      }
    }
    if(!flag)
      count++;

  } while (next_permutation(tmp, tmp + (H + W - 2)));

  cout << count << endl;

  return 0;
}
