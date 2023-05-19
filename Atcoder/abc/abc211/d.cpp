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

ll dijkstra(vvll& G, ll st, ll go) {
    vll dist(N + 1, INF), cnt(N + 1, 0);
    pqueue pq;
    pq.emplace(mp(1, st));
    dist[st] = 0;
    cnt[st] = 1;
    while (!pq.empty())
    {
        pair<ll, ll> pa = pq.top();
        pq.pop();
        ll cu = pa.second;
        for (auto nx : G[cu]) {
            if (dist[nx] == dist[cu] + 1)
                cnt[nx] = (cnt[nx] + cnt[cu]) % MOD;
            else if (dist[nx] > dist[cu] + 1) {
                dist[nx] = dist[cu] + 1;
                cnt[nx] = cnt[cu] % MOD;
                pq.emplace(mp(dist[cu] + 1, nx));
            }
        }
    }
    /*rep(i, N + 1) {
        cout << cnt[i] << ":";
    }
    cout << endl;*/
    if (dist[go] == INF)
        return 0;
    else
        return cnt[go];
}

int main()
{
    cin >> N >> M;
    vvll G(N + 1);
    rep(i, M) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vll dist(N + 1, INF), cnt(N + 1, 0);
    queue<ll> que;
    que.emplace(1);
    dist[1] = 0;
    cnt[1] = 1;
    while (!que.empty())
    {
        ll cu = que.front();
        que.pop();
        for (auto nx : G[cu]) {
            ll nxd = dist[cu] + 1;
            if (dist[nx] == nxd)
                cnt[nx] = (cnt[nx] + cnt[cu]) % MOD;
            else if (dist[nx] > nxd) {
                cnt[nx] = cnt[cu];
                dist[nx] = nxd;
                que.emplace(nx);
            }
        }
    }
    cout << cnt[N] << endl;

    return 0;
}