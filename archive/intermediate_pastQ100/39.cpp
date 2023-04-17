#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#include <numeric>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    rep(i, 0, N)
        cin >> nums[i];
    vector<vector<long long>> dp(N, vector<long long>(21, 0));
    dp[0][nums[0]] = 1;

    rep(i, 1, N - 1){
        rep(j, 0, 21){
            if(nums[i] <= j)
                dp[i][j] += dp[i - 1][j - nums[i]];
            if(j + nums[i] <= 20)
                dp[i][j] += dp[i - 1][j + nums[i]];
        }
    }
    long long ans = dp[N - 2][nums[N - 1]];

    cout << ans << endl;
    return 0;
}
