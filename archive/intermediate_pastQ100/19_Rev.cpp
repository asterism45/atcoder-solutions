#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res = 0, cnt = 0;
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
    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> D(n + 1), K(m);
    D[0] = 0;
    D[n] = d;
    rep(i, 1, n) cin >> D[i];
    sort(D.begin(), D.end());
    rep(i, 0, m) cin >> K[i];

    for(auto k : K){
        auto it = lower_bound(D.begin(), D.end(), k);
        res += min(abs(k - *it), abs(k - *(it - 1)));
    }

    cout << res << endl;

    return 0;
}
