#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <math.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res, cnt = 0;
ll dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    cin >> N;
    vector<string> S(N);
    rep(i, 0, N)
        cin >> S[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(2, -1));
    dp[0][1] = 1;
    dp[0][0] = 1;

    rep(i, 0, N) {
        if (S[i] == "AND") {
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][0] = 2 * dp[i][0] + dp[i][1];
        }
        else if (S[i] == "OR") {
            dp[i + 1][1] = 2 * dp[i][1] + dp[i][0];
            dp[i + 1][0] = dp[i][0];
        }
    }

    cout << dp[N][1] << endl;

    return 0;
}
