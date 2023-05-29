#include <bits/stdc++.h>
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
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

bool bs(vector<ll> S, ll key){
    ll left = -1;
    ll right = S.size();
    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        cout << mid << endl;
        if(S[mid] == key)
            return true;
        else if(S[mid] > key)
            right = mid;
        else
            left = mid;
    }
    return false;
}

int main()
{
    ll n, q;
    cin >> n;
    vector<ll> S(n);
    rep(i, 0, n)
        cin >> S[i];
    cin >> q;
    vector<ll> T(q);
    rep(i, 0, q){
        cin >> T[i];
    }
    rep(i,0,q){
        if(bs(S, T[i]))
            cnt++;
    }

    cout << cnt << endl;
    return 0;

}
