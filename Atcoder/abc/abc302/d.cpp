#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rreps(i, l, r) for (ll i = (l-1); i >= (r); i--)
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
bool comp(int a, int b) { return a > b; } //降順

int main()
{
    cin >> N >> M >> D;
    vll A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(all(B));
    ll res = -1;
    rep(i, N) {
        ll a = *lower_bound(all(B), A[i] - D);
        ll b;
        if (upper_bound(all(B), A[i] + D) == B.begin())
            b = *upper_bound(all(B), A[i] + D);
        else
            b = *(upper_bound(all(B), A[i] + D) - 1);
        ll af = 1, bf = 1;
        if (a < A[i] - D || A[i] + D < a) af = 0;
        if (b < A[i] - D || A[i] + D < b) bf = 0;
        if (af) res = max(res, a + A[i]);
        if (bf) res = max(res, b + A[i]);
        //cout << af << ":" << bf << endl;
        //cout << a << ":" << b << endl;
    }
    cout << res << endl;
    return 0;
}
