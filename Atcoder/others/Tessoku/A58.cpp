#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define INF ((1LL << 62) - (1LL << 31))
#define mp make_pair
#define MOD 1000000007
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

class SegmentTree {
public:
    ll siz = 1;
    vll dat;
    SegmentTree(ll N) {
        while (siz < N) siz *= 2;
        dat.resize(2 * siz);
        rep(i, 2 * siz) dat[i] = 0;
    }
    void update(ll pos, ll x) {
        ll num = pos + siz - 1;
        dat[num] = x;
        while ((num /= 2) != 0)
            dat[num] = max(dat[2 * num], dat[2 * num + 1]);
    }
    ll query(ll l, ll r, ll a, ll b, ll u) {
        if (b <= l || r <= a)
            return -INF;
        else if (l <= a && b <= r)
            return dat[u];

        ll m = (a + b) / 2;
        return max(query(l, r, a, m, 2 * u), query(l, r, m, b, 2 * u + 1));
    }
};

int main()
{
    cin >> N >> Q;
    SegmentTree st(N);
    while (Q-- > 0)
    {
        cin >> A;
        if (A == 1) {
            ll pos, x;
            cin >> pos >> x;
            st.update(pos, x);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << st.query(l, r, 1, st.siz + 1, 1) << endl;
        }
    }

    return 0;
}