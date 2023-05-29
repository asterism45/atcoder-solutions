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
    int T;
    cin >> T;

    vector<long long> ans(T);

    rep(k,0,T){
        long long N, D, K;
        cin >> N >> D >> K;
        K--;
        D = D % N;
        vector<bool> flag(N, false);
        flag[0] = true;
        int tmp = 0;
        rep(i,1,K + 1){
            int x = tmp +D;
            if(x >= N)
                x -= N;
            if(!flag[x]){
                flag[x] = true;
                tmp = x;
            }
            else{
                x++;
                while (flag[(x)]){
                    x++;
                    if(x == N)
                        x = 0;
                }
                flag[(x)] = true;
                tmp = x;
            }
        }
        ans[k] = tmp;
    }

    rep(k,0,T)
        cout << ans[k] << endl;
    
    return 0;
}


