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
bool rec(string S, string T, ll cu);


int main(){
    string S, T = "";
    cin >> S;

    ll num = 0;
    reverse(S.begin(), S.end());
    bool flag = false;

    while (num < S.size() && !flag)
    {
        switch (S[num])
        {
        case 'm':
            T.append("maerd");
            num += 5;
            break;
        case 'e':
            T.append("esare");
            num += 5;
            break;
        case 'r':
            if(num + 2 < S.size()){
                switch (S[num + 2])
                {
                case 'm':
                    T.append("remaerd");
                    num += 7;
                    break;
                case 's':
                    T.append("resare");
                    num += 6;
                    break;
                
                default:
                    flag = true;
                    break;
                }
            }
        
        default:
            flag = true;
            break;
        }
    }
    
    if(S == T)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}