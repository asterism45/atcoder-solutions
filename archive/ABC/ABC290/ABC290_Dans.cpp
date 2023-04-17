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
using ll = long long;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}


int main(){
    int T;
    cin >> T;
    vector<long long> ans(T);
    rep(k,0,T)
    {
        long long N, D, K;
        cin >> N >> D >> K;
        --K;
        long long n = N / gcd(N, D);
        ans[k] = (K / n) + (K * D) % N;
    }

    rep(k,0,T)
        cout << ans[k] << endl;

    return 0;
}


