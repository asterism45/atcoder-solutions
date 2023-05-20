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
ll dy[8] = { 1, -1, 0, 0, 1,1,-1,-1 }, dx[8] = { 0, 0, 1, -1, 1,-1,1,-1, };
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void outp(bool flag) { cout << (flag ? "Yes" : "No") << endl; }
bool comp(int a, int b) { return a > b; } //降順

bool inrange(ll y, ll x) {
    if (0 <= y && y <= H - 1 && 0 <= x && x <= W - 1)
        return 1;
    else
        return 0;
}

int main()
{
    cin >> H >> W;
    vvc S(H, vc(W));
    rep(i, H) {
        rep(j, W) {
            cin >> S[i][j];
        }
    }
    rep(y, H) {
        rep(x, W) {
            if (S[y][x] == 'u') {
                rep(p, 8) {
                    ll ny = y + dy[p], nx = x + dx[p];
                    if (inrange(ny, nx) && S[ny][nx] == 'n') {
                        ll rny = y - dy[p], rnx = x - dx[p];
                        if (inrange(rny, rnx) && S[rny][rnx] == 'k') {
                            ll nny = y + 2 * dy[p], nnx = x + 2 * dx[p];
                            if (inrange(nny, nnx) && S[nny][nnx] == 's') {
                                ll rrny = y - 2 * dy[p], rrnx = x - 2 * dx[p];
                                if (inrange(rrny, rrnx) && S[rrny][rrnx] == 'e') {
                                    cout << nny + 1 << " " << nnx + 1 << endl;
                                    cout << ny + 1 << " " << nx + 1 << endl;
                                    cout << y + 1 << " " << x + 1 << endl;
                                    cout << rny + 1 << " " << rnx + 1 << endl;
                                    cout << rrny + 1 << " " << rrnx + 1 << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}