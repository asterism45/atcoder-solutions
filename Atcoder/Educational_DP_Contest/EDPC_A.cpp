#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int N;
    cin >> N;
    vector<int> h(N + 1);
    rep(i,1,N + 1)
        cin >> h[i];
    
    vector<int> dp(N + 1);
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);

    rep(i,3,N+1){
        if((dp[i - 1] + abs(h[i] - h[i - 1])) > (dp[i - 2] + abs(h[i] - h[i - 2])))
            dp[i] = dp[i - 2] + abs(h[i] - h[i - 2]);
        else
            dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    }


    cout << dp[N] << endl;
    
    return 0;
}


