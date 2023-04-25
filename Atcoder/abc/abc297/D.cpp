#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res, cnt = 0;
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
    cin >> A >> B;
    while (A != B)
    {
        // cout << A << " " << B << endl;
        if (A == 1)
        {
            cnt += B - 1;
            break;
        }
        else if (B == 1)
        {
            cnt += A - 1;
            break;
        }
        else if (A > B)
        {
            if (A % B == 0)
            {
                cnt += A / B - 1;
                break;
            }
            else
            {
                ll tmp = A / B;
                A %= B;
                cnt += tmp;
            }
        }
        else if (A < B)
        {
            if (B % A == 0)
            {
                cnt += B / A - 1;
                break;
            }
            else
            {
                ll tmp = B / A;
                B %= A;
                cnt += tmp;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
