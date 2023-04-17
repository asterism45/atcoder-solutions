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
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}


int main(){
    long long ans;
    long long num = 998244353;
    int N;
    cin >> N;
    vector<vector<int>> AB(N + 1, vector<int>(2));
    rep(i,1,N + 1)
        cin >> AB[i][0] >> AB[i][1];
    
    vector<vector<int>> dp(N + 1, vector<int>(2));

    dp[1][0] = 1;
    dp[1][1] = 1;

    rep(i,2,N + 1){
        rep(j,0,2){
            if(AB[i][j] != AB[i - 1][0])
                dp[i][j] += dp[i - 1][0];
            if(AB[i][j] != AB[i - 1][1])
                dp[i][j] += dp[i - 1][1];
            dp[i][j] %= num;
        }
    }

    ans = (dp[N][0] + dp[N][1]) % num;

    cout <<  ans << endl;
    
    return 0;
}


