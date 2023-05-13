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

ll wgt = 1e13;
vll dijkstra(const vector<vector<pair<ll, ll>>>& G, ll r, ll p, ll n, const vll& A) {
    vll dist(n + 1, INF), flag(n + 1, 0);
    pqueue pq;
    pq.push(mp(0, r));
    dist[r] = -A[r];
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        auto s = top.second;
        flag[s] = 1;
        for (auto nx : G[s]) {
            auto t = nx.second;
            if (flag[t] == 0) {
                if (dist[t] <= dist[s] + wgt - A[t])
                    continue;
                dist[t] = dist[s] + wgt - A[t];
                pq.push(mp(dist[s] + wgt - A[t], t));
            }
        }
    }
    return dist;
}

int main()
{
    cin >> N;
    vll A(N + 1);
    reps(i, 1, N + 1) cin >> A[i];
    vector<vector<pair<ll, ll>>> G(N + 1);
    reps(i, 1, N + 1) {
        string S;
        cin >> S;
        rep(j, N) {
            if (S[j] == 'Y')
                G[i].push_back(mp(1, j + 1));
        }
    }
    cin >> Q;
    vvll res(N + 1);
    while (Q-- > 0)
    {
        cin >> U >> V;
        if (res[U].empty())
            res[U] = dijkstra(G, U, V, N, A);
        if (res[U].at(V) != INF) {
            ll dis = res[U][V] / wgt, val = wgt - res[U][V] % wgt;
            //if (val < 0) val += wgt;
            cout << ++dis << " " << val << endl;
        }
        else
            cout << "Impossible" << endl;
    }

    return 0;
}