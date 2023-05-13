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
    cin >> H >> W >> T;
    vvc A(H, vc(W));
    rep(i, H) {
        rep(j, W)cin >> A[i][j];
    }
    vector<vector<char>> dist(H, vector<char>(W, -1));
    queue<pair<int, int>> que;

    dist[0][0] = 0;
    que.push(make_pair(0, 0));

    while (!que.empty())
    {
        pair<int, int> yx;
        yx = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = yx.first + dy[i], next_x = yx.second + dx[i];
            if (next_y < h && next_y > -1 && next_x < w && next_x > -1)
            {
                ll bo;
                if (s[next_y][next_x] == '#')
                    continue;
                if (s[next_y][next_x] == 'o')
                    bo--;
                dist[next_y][next_x] = dist[yx.first][yx.second] + 1;
                que.push(make_pair(next_y, next_x));
            }
        }
    }

    if (dist[h - 1][w - 1] == -1)
    {
        cout << -1 << endl;
        return 0;
    }


    int count = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (dist[i][j] != -1 || (dist[i][j] == -1 && s[i][j] == '.'))
                count++;
        }
    }

    if (count - (dist[h - 1][w - 1] + 1) < 0)
        cout << 0 << endl;
    else
        cout << (count - (dist[h - 1][w - 1] + 1)) << endl;
    return 0;
}