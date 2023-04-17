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
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int gcd(int a, int b)
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
    ll N, Q;
    cin >> N >> Q;
    vector<int> T(Q), A(Q), B(Q);
    set<pair<unsigned, unsigned>> follows;
    //vector<vector<ll>> user(N + 3, vector<ll>(N + 3, -1));

    rep(i, 0, Q)
            cin >> T[i] >> A[i] >> B[i];

    rep(i, 0, Q)
    {
        switch (T[i])
        {
        case 1:
            follows.emplace(A[i], B[i]);
            break;
        case 2:
            follows.erase({A[i], B[i]});
            break;
        case 3:
            if (follows.count({A[i], B[i]}) && follows.count({B[i], A[i]}))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;

        default:
            break;
        }
    }

    return 0;
}
