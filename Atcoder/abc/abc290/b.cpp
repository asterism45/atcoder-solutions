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

int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<char> ans(N);
    int count = 0;
    rep(i, 0, N)
    {
        if (S[i] == 'o')
        {
            if (count < K)
            {
                ans[i] = 'o';
                count++;
            }
            else
            {
                ans[i] = 'x';
            }
        }
        else
        {
            ans[i] = 'x';
        }
    }

    rep(i, 0, N)
            cout
        << ans[i];

    cout << endl;

    return 0;
}