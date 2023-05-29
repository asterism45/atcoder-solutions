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
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size();

    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1));

    dp[0][0] = 0;

    for (int i = 0; i < slen; i++)
    {
        for (int j = 0; j < tlen; j++)
        {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            if (s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
        }
    }

    int anslen = dp[slen][tlen];
    vector<string> ans(anslen);
    int len = anslen;

    while(anslen > 0){
        if (s[slen - 1] == t[tlen - 1]){
            ans[anslen - 1] = s[slen - 1];
            anslen--;
            slen--;
            tlen--;
        }
        else if (dp[slen - 1][tlen] == dp[slen][tlen])
            slen--;
        else
            tlen--;
    }

    for (int i = 0; i < len; i++)
    {
        cout << ans[i];
    }

    cout << endl;
    
    
    return 0;
}


