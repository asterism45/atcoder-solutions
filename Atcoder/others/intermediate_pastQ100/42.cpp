#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> D(N + 1), C(M + 1);
    rep(i, 1, N + 1)
        cin >> D[i]; // the distance between city i-1 and city i
    rep(i, 1, M + 1)
        cin >> C[i]; // the climate of day i

    vector<vector<long long>> dp(M + 1, vector<long long>(N + 1, -1));

    dp[0][0] = 0;

    rep(i, 1, M + 1){
        rep(j, 0, N + 1){
            if(j == 0)
                dp[i][0] = dp[i - 1][0];
            else if(j > i)
                continue;
            else{
                if(dp[i - 1][j] != -1)
                    dp[i][j] = min(dp[i - 1][j], (dp[i - 1][j - 1] + D[j] * C[i]));
                else{
                    if(dp[i - 1][j - 1]  == -1)
                        dp[i - 1][j - 1]++;
                    dp[i][j] = dp[i - 1][j - 1] + D[j] * C[i];
                }
            }
        }
    }

    /*rep(i,1,M+1){
        rep(j,0,N+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp[M][N] << endl;
    
    return 0;
}


