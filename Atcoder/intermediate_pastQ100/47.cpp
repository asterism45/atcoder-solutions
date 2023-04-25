#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

int N;
vector<int> A(2 * N + 2);
// dp[i][j]:= iからjまでのケーキを互いに取った時の最大値
vector<vector<long>> dp(N + 1, vector<long>(2 * N + 2, -1));

int solve(int i, int j)
{
    if (i > j)
        return 0;
    else if (dp[i][j] != -1)
        return dp[i][j];
    else
    {
        if ((N - (j - i + 1)) % 2 == 0)
        {
            dp[i][j] = max(solve(i + 1, j) + A[i], solve(i, j - 1) + A[j]);
            return dp[i][j];
        }
        else
        {
            if (A[i] > A[j])
            {
                dp[i][j] = solve(i + 1, j);
                return dp[i][j];
            }
            else
            {
                dp[i][j] = solve(i, j - 1);
                return dp[i][j];
            }
        }
    }
}

int main()
{
    cin >> N;
    rep(i, 1, N + 1)
    {
        cin >> A[i];
        A[i + N] = A[i];
    }

    int ans = 0;

    rep(i, 1, N + 1)
    {
        ans = max(ans, A[N - i + 1] + solve(i, i + N - 1));
    }

    cout << ans << endl;

    return 0;
}
