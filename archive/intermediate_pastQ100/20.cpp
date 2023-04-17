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
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i,0,N)
        cin >> A[i];
    sort(A.begin(), A.end());
    rep(i,0,N)
        cin >> B[i];
    rep(i,0,N)
        cin >> C[i];
    sort(C.begin(), C.end());
    
    for(auto b:B){
        ll cnta = A.size() - distance(lower_bound(A.begin(), A.end(), b), A.end());
        ll cntc = distance(lower_bound(C.begin(), C.end(), b + 1), C.end());
        res += cnta * cntc;
    }

    cout << res << endl;

    return 0;
}
