#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int n, W;
    cin >> n >> W;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int w = 0; w < W + 1; w++)
        {
            if (w >= weight[i])
                dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            else
                dp[i + 1][w] = dp[i][w];
        }
    }

    cout << dp[n - 1][W];
    
    return 0;
}


