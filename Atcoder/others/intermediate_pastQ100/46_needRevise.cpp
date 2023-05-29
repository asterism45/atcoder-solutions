#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> p(n + 1);
    rep(i, 1, n + 1)
        cin >> p[i - 1] >> p[i];


    
    vector<vector<long>> dp(n + 1, vector<long>(n + 1, 100000000));
    rep(l, 2, n + 1){
        rep(i, 1, n + 1 - l){
            int j = i + l - 1;
            dp[i][j] = 100000000;
            rep(k,i,j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
        }
    }
    
    cout << dp[1][n] << endl;

    return 0;
}


