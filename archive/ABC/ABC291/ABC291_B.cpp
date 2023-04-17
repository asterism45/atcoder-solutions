#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <math.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
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
    int N;
    cin >> N;
    vector<int> X(5 * N);
    double mean = 0;
    rep(i,0,5*N)
        cin >> X[i];
    
    sort(X.begin(), X.end());
    rep(i,N,4*N)
        mean += X[i];
    
    mean /= 3*N;

    cout << mean << endl;
    
    return 0;
}


