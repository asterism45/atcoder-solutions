#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res = 0;
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
    cin >> N >> M;
    vll k(M), p(M);
    vvll s(M, vll(10));
    rep(i, 0, M)
    {
        cin >> k[i];
        rep(j, 0, k[i])
                cin >> s[i][j];
    }
    rep(i, 0, M)
            cin >> p[i];

    for (ll bit = 0; bit < (1 << N); ++bit)
    {
        vector<bool> flag(N + 1, 0);
        bool check = true;
        rep(i, 0, N)
        {
            if (bit & (1 << i))
                flag[i + 1] = 1;
        }
        rep(i, 0, M)
        {
            ll cnt = 0;
            rep(j, 0, k[i])
            {                
                if (flag[s[i][j]] == 1)
                    cnt++;
            }
            if (cnt % 2 != p[i])
                check = false;
        }
        if(check)
            res++;
    }

    cout << res << endl;

    return 0;
}
