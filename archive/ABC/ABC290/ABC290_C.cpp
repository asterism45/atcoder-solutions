#include <string>
#include <vector>
#include <iostream>
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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,0,N)
        cin >> A[i];

    int num = 0;

    vector<bool> flag(N + 1, false);
    
    rep(i,0,N){
        if(A[i] <= K) 
            flag[A[i]] = true;
    }
    
    while (flag[num])
    {
        num++;
    }
    

    if(num > K)
        cout << K << endl;
    else
        cout << num << endl;
    
    return 0;
}