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
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, J, K, L, M, N, P, Q, S, T, U, X, Y, Z;
ll ans;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
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
    cin >> N >> Q;
    vector<ll> event(Q), x(Q, -1), flag(N, 0);
    rep(i, 0, Q)
    {
        cin >> event[i];
        if (event[i] == 2)
            cin >> x[i];
    }

    ll count = 0, min = 0;

    rep(i, 0, Q)
    {
        switch (event[i])
        {
        case 1:
            flag[count] = 1;
            count++;
            break;
        case 2:
            flag[x[i] - 1] = 0;
            if (min >= x[i] - 1)
            {
                while (flag[min] != 1 && min < N - 1)
                {
                    min++;
                }
            }
            break;
        case 3:
            cout << min + 1 << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
