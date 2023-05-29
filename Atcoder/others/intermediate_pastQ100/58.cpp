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

ll dij(vector<vector<pair<ll, ll>>>& G) {
    vll cost(N + 1, INF);
    pqueue pq;
    cost[1] = 0;
    pq.emplace(mp(0, 1));
    while (!pq.empty())
    {
        ll cu = pq.top().second;
        pq.pop();
        for (auto nx : G[cu]) {
            ll nxc = cost[cu] + nx.first;
            ll nxn = nx.second;
            if (cost[nxn] > nxc) {
                cost[nxn] = nxc;
                pq.emplace(mp(nxc, nxn));
            }
        }
    }
    /*reps(i, 1, N + 1) cout << cost[i] << ":";
    cout << endl;*/
    return cost[N];
}

int main()
{
    cin >> N >> M >> K >> S >> P >> Q;
    vll f(N + 1, 0), C(K);
    rep(i, K) cin >> C[i];
    vll A(M), B(M);
    vvll G(N + 1);
    rep(i, M) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    queue<ll> que;
    vll dist(N + 1, INF);
    rep(i, K) {
        que.emplace(C[i]);
        dist[C[i]] = 0;
    }

    while (!que.empty())
    {
        ll cu = que.front();
        que.pop();
        for (auto nx : G[cu]) {
            if (dist[nx] > dist[cu] + 1) {
                dist[nx] = dist[cu] + 1;
                que.emplace(nx);
            }
        }
    }
    rep(i, N + 1) {
        if (dist[i] == 0)
            f[i] = 2;
        else if (dist[i] <= S)
            f[i] = 1;
    }
    //reps(i, 1, N + 1) cout << f[i] << ":";
    //cout << endl;
    vector<vector<pair<ll, ll>>> Gp(N + 1);
    rep(i, M) {
        if (f[A[i]] == 2 || f[B[i]] == 2)
            continue;
        ll ad, bd;
        if (f[A[i]]) ad = Q;
        else ad = P;
        if (f[B[i]]) bd = Q;
        else bd = P;
        Gp[A[i]].push_back(mp(bd, B[i]));
        Gp[B[i]].push_back(mp(ad, A[i]));
        //cout << "f[A[i]]" << f[A[i]] << " A[i]:" << A[i] << " B[i]" << B[i] << " bd:" << ad << endl;
    }

    ll res = dij(Gp);
    if (f[N]) res -= Q;
    else res -= P;
    cout << res << endl;

    return 0;
}