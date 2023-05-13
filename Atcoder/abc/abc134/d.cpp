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

int main()
{
    cin >> N;
    vll a(N + 1), b(N + 1, -1);
    reps(i, 1, N + 1) cin >> a[i];
    for (ll i = N; i > 0; i--)
    {
        ll cnt = 0, num = N / i, ind = i;
        rep(j, num) {
            if (b[ind]) cnt++;
            ind += i;
        }
        if (cnt % 2 == 1)
            b[i] = a[i];
        else
            b[i] = !a[i];
    }
    ll res = 0;
    reps(i, 1, N + 1)
        if (b[i]) res++;
    cout << res << endl;
    ll f = 0;
    reps(i, 1, N + 1) {
        if (b[i]) {
            if (f)
                cout << " " << i;
            else {
                cout << i;
                f = 1;
            }
        }
    }
    if (f) cout << endl;
    return 0;
}