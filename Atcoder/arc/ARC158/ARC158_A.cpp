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
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, J, K, L, M, N, P, Q, S, T, U, X, Y, Z;
ll ans;
ll dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}


int main(){

    cin >> T;
    ll tmp = T;
    vector<ll> ans(T);

    while (tmp > 0)
    {
        tmp--;
        vector<ll> x(3);
        rep(i,0,3)
            cin >> x[i];
        
        sort(x.begin(), x.end());
        vector<ll> dx(2);
        dx[0] = x[1] - x[0];
        dx[1] = x[2] - x[1];
        sort(dx.begin(), dx.end());
        ll count = 0;
        
        
        if(dx[0] % 2 == 0 && dx[1] % 2 == 0){
            count += dx[0] / 2;
            dx[1] -= dx[0];
            if(dx[1] % 6 == 0){
                count += (dx[1] / 6) * 2;
                ans[tmp] = count;
            }
            else{
                ans[tmp] = -1;
            }
        }
        else{
            ans[tmp] = -1;
        }
    }

    for (ll i = T - 1; i >= 0; i--)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}


