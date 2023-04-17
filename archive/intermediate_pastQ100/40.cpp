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
#define MOD 10000
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){

    int N, K;
    cin >> N >> K;
    vector<int> A(K), B(K);
    vector<vector<int>> flag(N + 1, vector<int>(2,0));
    rep(i,0,K){
        cin >> A[i] >> B[i];
        B[i]--;
        flag[A[i]][0] = 1;
        flag[A[i]][1] = B[i];
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(3,vector<int>(3, 0)));

    rep(j,0,3){
        rep(k,0,3){
            if(flag[1][0] & flag[2][0]){
                if(j == flag[2][1] && k == flag[1][1])
                    dp[2][j][k] = 1;
            }
            else if(flag[1][0]){
                if(k == flag[1][1])
                    dp[2][j][k] = 1;
            }
            else if(flag[2][0]){
                if(j == flag[2][1])
                    dp[2][j][k] = 1;
            }
            else{
                dp[2][j][k] = 1;
            }
        }
    }

    rep(i, 3, N + 1){
        rep(j, 0, 3){
            rep(k, 0, 3){
                if (flag[i][0])
                {
                    if (j == flag[i][1])
                    {
                        switch (k)
                        {
                            case 0:
                                dp[i][j][k] += (dp[i - 1][k][1] + dp[i - 1][k][2]) % MOD;
                                break;
                            case 1:
                                dp[i][j][k] += (dp[i - 1][k][0] + dp[i - 1][k][2]) % MOD;
                                break;
                            case 2:
                                dp[i][j][k] += (dp[i - 1][k][0] + dp[i - 1][k][1]) % MOD;
                                break;
                            default:
                                break;
                        }
                        if(j != k)
                            dp[i][j][k] += dp[i - 1][k][k] % MOD;
                    }
                }
                else{
                    switch (k)
                    {
                    case 0:
                        dp[i][j][k] += (dp[i - 1][k][1] + dp[i - 1][k][2]) % MOD;
                        break;
                    case 1:
                        dp[i][j][k] += (dp[i - 1][k][0] + dp[i - 1][k][2]) % MOD;
                        break;
                    case 2:
                        dp[i][j][k] += (dp[i - 1][k][0] + dp[i - 1][k][1]) % MOD;
                        break;
                    default:
                        break;
                    }
                    if(j != k)
                        dp[i][j][k] += dp[i - 1][k][k] % MOD;
                }
                
            }
        }
    }

    int ans = 0;
    rep(j,0,3){
        rep(k,0,3){
            ans += dp[N][j][k];
        }
    }
    ans %= MOD;

    cout << ans << endl;
    
    return 0;
}


