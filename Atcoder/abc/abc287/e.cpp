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
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    map<__uint128_t, vll> mp;
    vll res(N, 0);
    rep(i, N) {
        vector<__uint128_t> h(S[i].size() + 1, 0);
        __uint128_t m = 1;
        rep(j, S[i].size()) {
            __uint128_t p = S[i][j] - 'a' + 1;
            h[j + 1] = h[j] + p * m;
            if (mp[h[j + 1]].empty())
                mp[h[j + 1]].push_back(i);
            else {
                ll ind = mp[h[j + 1]].back();
                if (i != ind) {
                    mp[h[j + 1]].push_back(i);
                    res[i] = max(res[i], j + 1);
                    res[ind] = max(res[ind], j + 1);
                }
            }
            m *= MOD;
        }
    }
    rep(i, N)
        cout << res[i] << endl;
    return 0;
}