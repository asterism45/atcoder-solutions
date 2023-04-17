#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
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

bool isOk(ll N, vector<ll> H, vector<ll> S, ll key)
{
    vector<ll> P(N);
    rep(i,0,N){
        P[i] = (key - H[i]) / S[i];
        if(key - H[i] < 0)
            return false;
    }
    sort(P.begin(), P.end());
    rep(i,0,N){
        if(P[i] < i)
            return false;
    }
    return true;
}

ll bs(ll N, vector<ll> H, vector<ll> S)
{
    ll ng = *min_element(H.begin(), H.end()), ok = *max_element(H.begin(), H.end()) + *max_element(S.begin(), S.end()) * N;
    while (ok - ng > 1)
    {
        ll mid = (ng + ok) / 2;
        if (isOk(N, H, S, mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main()
{
    cin >> N;
    vector<ll> H(N), S(N), sum(N);
    rep(i, 0, N)
        cin >> H[i] >> S[i];
    cout << bs(N, H, S) << endl;
    return 0;
}
