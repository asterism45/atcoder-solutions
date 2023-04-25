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
    int D, N;
    cin >> D >> N;
    vector<int> T(D + 1);
    vector<int> A(N), B(N), C(N);
    rep(i, 1, D + 1)
        cin >> T[i];
    rep(i, 0, N)
        cin >> A[i] >> B[i] >> C[i];
    
    vector<vector<long>> dp(D + 1, vector<long>(N, -1));
    rep(j, 0, N){
        if(A[j] <= T[1] && T[1] <= B[j])
            dp[1][j] = 0;
    }



    rep(i, 2, D + 1){
        rep(j, 0, N){
            long maxvalue = 0;
            if (A[j] <= T[i] && T[i] <= B[j]){
                rep(k, 0, N)
                    if (dp[i - 1][k] != -1)
                        maxvalue = max(maxvalue, (dp[i - 1][k] + abs(C[k] - C[j])));
            }
            dp[i][j] = maxvalue;
        }
    }

    long ans = 0;
    rep(j, 0, N){
        ans = max(ans, dp[D][j]);
    }

    cout << ans << endl;
    
    return 0;
}


