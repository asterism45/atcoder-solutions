#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res=0, cnt = 0;
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

struct Res
{
    ll key;
    ll value;
};

Res bs(vector<ll> D, ll k){
    ll ok = D.size(), ng = -1;
    ll mid;
    Res r;
    while (abs(ok - ng) > 1)
    {
        mid = (ok + ng) / 2;
        if(D[mid] == k){
            r.key = mid;
            r.value = k;
            return r;
        }
        else if(D[mid] > k)
            ok = mid;
        else
            ng = mid;
    }
    r.key = ok;
    r.value = D[ok];
    return r;
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
    
    rep(i,0,m){
        Res r = bs(D, K[i]);
        //cout << r.value << " " << abs(K[i] - r.value) << " " << abs(K[i] - D[r.key - 1]) << endl;
        if(abs(K[i] - r.value) >= abs(K[i] - D[r.key - 1]))
            res += abs(K[i] - D[r.key - 1]);
        else
            res += abs(K[i] - r.value);
    }

    cout << res << endl;

    return 0;
}
