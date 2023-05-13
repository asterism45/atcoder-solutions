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
bool comp(int a, int b) { return a > b; } //降順

int main()
{
    string S, T;
    cin >> S >> T;
    vll s(26, 0), t(26, 0);
    ll ats = 0, att = 0;
    rep(i, S.size()) {
        if (S[i] == '@') {
            ats++;
            continue;
        }
        ll nm1 = S[i] - 97;
        s[nm1]++;
    }
    rep(i, T.size()) {
        if (T[i] == '@') {
            att++;
            continue;
        }
        ll nm2 = T[i] - 97;
        t[nm2]++;
    }
    ll scnt = 0, tcnt = 0, f = 1;
    rep(i, 26) {
        if (i == 0 || i == 2 || i == 3 || i == 4 || i == 14 || i == 17 || i == 19) {
            if (s[i] < t[i]) {
                scnt += t[i] - s[i];
            }
            else if (s[i] > t[i])
                tcnt += s[i] - t[i];
        }
        else {
            if (s[i] != t[i]) {
                f = 0;
            }
        }
    }
    if (scnt > ats || tcnt > att) {
        f = 0;
    }
    outp(f);
    return 0;
}