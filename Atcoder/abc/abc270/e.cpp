#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define INF ((1LL << 62) - (1LL << 31))
#define mp make_pair
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

ll f(const vll& a, ll loop) {
    ll cnt = 0;
    rep(i, N)
        cnt += min(loop, a[i]);
    if (cnt >= K)
        return 1;
    else
        return 0;
}

int main()
{
    cin >> N >> K;
    vll A(N);
    rep(i, N)
        cin >> A[i];
    ll ng = 0, ok = K + 1, mid;
    while (ok - ng > 1) {
        mid = (ok + ng) / 2;
        if (f(A, mid))
            ok = mid;
        else
            ng = mid;
    }
    rep(i, N) {
        ll  d = min(ng, A[i]);
        A[i] -= d;
        K -= d;
    }
    for (ll p = 0; K > 0;p++)
    {
        if (A[p] > 0) {
            A[p]--;
            K--;
        }
    }
    rep(i, N)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}