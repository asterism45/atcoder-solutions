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
ll cal(ll num);
ll pownum(ll num, ll i)
{
    ll res = 1;
    rep(j, 0, i)
    {
        res *= num;
    }
    return res;
}

int main()
{
    cin >> A;
    bool flag = false;
    rep(i, 10, 10001)
    {
        if (cal(i) == A)
        {
            cout << i << endl;
            flag = true;
            break;
        }
    }

    if (!flag)
        cout << -1 << endl;

    return 0;
}
ll cal(ll num)
{
    ll tmp = num, i = 0, res = 0;
    while (tmp != 0)
    {
        ll digitnum = tmp % 10;
        res += digitnum * pownum(num, i);
        i++;
        tmp /= 10;
    }

    return res;
}
