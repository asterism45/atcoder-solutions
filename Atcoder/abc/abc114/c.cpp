#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rreps(i, l, r) for (ll i = (l); i >= (r); i)
#define INF ((1LL << 62) - (1LL << 31))
#define mp make_pair
#define pb push_back
#define MOD 1000000007 //998244353
#define all(a) (a).begin(), (a).end()
using ll = long long;
using vll = vector<ll>;
using vc = vector<char>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void outp(bool flag) { cout << (flag ? "Yes" : "No") << endl; }

ll res = 0;
void dfs(ll nm, ll n) {
    if (nm > n)
        return;
    bool f1 = 0, f2 = 0, f3 = 0;
    ll num = nm;
    while (nm != 0)
    {
        ll dig = nm % 10;
        nm /= 10;
        if (dig == 3)
            f1 = 1;
        if (dig == 5)
            f2 = 1;
        if (dig == 7)
            f3 = 1;
    }
    if (f1 && f2 && f3)
        res++;
    dfs((num * 10 + 3), n);
    dfs((num * 10 + 5), n);
    dfs(num * 10 + 7, n);
}

int main()
{
    cin >> N;
    dfs(0, N);
    cout << res << endl;
    return 0;
}