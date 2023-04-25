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
    long long X, K, D;
    cin >> X >> K >> D;
    
    long long ans;

    if (abs(X) / D >= K)
    {
        if(X >= 0)
            ans = X - (K * D);
        else
            ans = X + (K * D);
    }
    else
    {
        long long num = D * (abs(X) / D);
        long long tmp1, tmp2;
        if (X >= 0)
        {
            tmp1 = X - num;
            tmp2 = tmp1 - D;
            if((K - (abs(X) / D)) % 2 == 0)
                ans = tmp1;
            else
                ans = tmp2;
        }
        else
        {
            tmp1 = X + num;
            tmp2 = tmp1 + D;
            if((K - (abs(X) / D)) % 2 == 0)
                ans = tmp1;
            else
                ans = tmp2;
        }
        
    }

    cout << abs(ans) << endl;
    
    return 0;
}


