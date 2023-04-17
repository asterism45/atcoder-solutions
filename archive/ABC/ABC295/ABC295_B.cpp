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
ll A, B, C, D, F, G, J, K, L, M, N, P, Q, S, T, U, X, Y, Z, R;
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
  cin >> R >> C;
  vector<vector<char>> B(R, vector<char>(C));
  rep(i,0,R){
    rep(j,0,C)
      cin >> B[i][j];
  }

  rep(i,0,R){
    rep(j,0,C){
      if(B[i][j] != '#' && B[i][j] != '.'){
        ll num = B[i][j] - '0';
        rep(p,0,R){
          rep(q,0,C){
            if(((abs(p - i) + abs(q - j)) <= num) && B[p][q] == '#')
              B[p][q] = '.';
          }
        }
        B[i][j] = '.';
      }
    }
  }

  rep(i,0,R){
    rep(j,0,C)
      cout << B[i][j];
    cout << endl;
  }

  return 0;
}
