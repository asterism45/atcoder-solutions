#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int N;
    cin >> N;
    vector<vector<int>> H(N + 1, vector<int>(3));
    rep(i,1,N + 1)
        cin >> H[i][0] >> H[i][1] >> H[i][2];

    vector<vector<int>> dp(N + 1,vector<int>(3, 0)); // A = 0, B = 1, C = 2
    
    dp[1][0] = H[1][0];
    dp[1][1] = H[1][1];
    dp[1][2] = H[1][2];

    rep(i,2,N + 1){
        rep(j,0,3){
            switch (j)
            {
            case 0:
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + H[i][0];
                break;
            case 1:
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + H[i][1];
                break;
            case 2:
                dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + H[i][2];
                break;
            default:
                break;
            }
        }
    }


    cout << max({dp[N][0], dp[N][1], dp[N][2]}) <<endl;
    
    return 0;
}


