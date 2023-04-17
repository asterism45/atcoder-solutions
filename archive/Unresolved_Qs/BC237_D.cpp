// 両端queue問題

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
    string S;
    cin >> N >> S;
    vector<int> ans(2000000, -1);
    int std = 1000000;
    int lcount = 0, rcount = 0;
    ans[std] = N;

    for (int i = N - 1; i >= 0; i--)
    {
        if (S[i] == 'L')
        {
            lcount++;
            ans[std + lcount] = i;
        }
        else
        {
            rcount++;
            ans[std - rcount] = i;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != -1)
        {
            cout << ans[i] << " ";
        }
        
    }
    
    
    
    return 0;
}