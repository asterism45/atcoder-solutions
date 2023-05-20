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
#define INF ((1LL<<31)-(1LL<<16)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };
int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}


int main() {
    int N, X;
    cin >> N >> X;
    vector<int> x(N);
    rep(i, 0, N) {
        cin >> x[i];
        x[i] = abs(x[i] - X);
    }

    int D = INF;

    if (N == 1) {
        cout << x[0];
        return 0;
    }

    rep(i, 0, N - 1)
        D = min(D, gcd(x[i], x[i + 1]));

    cout << D << endl;

    return 0;
}


