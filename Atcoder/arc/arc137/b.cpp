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
    cin >> N;
    ll countone = 0, renzoku = 0, renzokuone = 0;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }
    ll ma = 0, maone = 0, onepre = -5, pre = -4;
    rep(i, N) {
        if (A[i] == 1 && onepre == i - 1) {
            countone++;
            renzokuone++;
            onepre = i;
        }
        else if (A[i] == 0 && pre != i - 1) {
            maone = max(maone, renzokuone);
            renzokuone = 1;
            onepre = i;
        }
        else if (A[i] == 0 && pre == i - 1) {
            renzoku++;
            pre = i;
        }
        else if (A[i] == 0 && pre != i - 1) {
            ma = max(ma, renzoku);
            renzoku = 1;
            pre = i;
        }
    }
    cout << ma + maone + 1 << endl;
    return 0;
}