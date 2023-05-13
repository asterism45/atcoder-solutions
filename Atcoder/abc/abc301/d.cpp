#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rreps(i, l, r) for (ll i = (l); i >= (r); i--)
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
    string S;
    cin >> S;
    cin >> T;
    ll num = T;
    vll binary;
    while (num > 0) {
        binary.push_back(num % 2);
        num = num / 2;
    }
    reverse(binary.begin(), binary.end());
    ll f = 1, ok = 0;
    if (S.size() < binary.size()) {
        rep(i, S.size()) {
            if (S[i] == '?') S[i] = '1';
        }
    }
    else {
        rep(i, S.size()) {
            if (i < (S.size() - binary.size()) && S[i] == '1') {
                f = 0;
            }
            if (i >= (S.size() - binary.size()) && (S[i] == '1' && binary[i - (S.size() - binary.size())] == 0)) {
                f = 0;
            }
            if (i >= (S.size() - binary.size()) && (S[i] == '0' && binary[i - (S.size() - binary.size())] == 1)) {
                ok = 1;
            }
            if (S[i] == '?') {
                if (i < (S.size() - binary.size())) {
                    S[i] = '0';
                }
                else if (ok) {
                    S[i] = '1';
                }
                else if (binary[i - (S.size() - binary.size())] == 1)
                    S[i] = '1';
                else if (binary[i - (S.size() - binary.size())] == 0)
                    S[i] = '0';
            }
        }
    }
    if (f) {
        ll decimal = 0;
        ll base = 1;

        for (ll i = S.size() - 1; i >= 0; i--) {
            decimal += (ll)((S[i] - 48) * base);
            base *= 2ll;
        }
        cout << decimal << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}