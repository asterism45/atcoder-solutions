#pragma region header
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep1(a)          for(ll i = 0; i < a; i++)
#define rep2(i, a)       for(ll i = 0; i < a; i++)
#define rep3(i, a, b)    for(ll i = a; i < b; i++)
#define rep4(i, a, b, c) for(ll i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(a)         for(ll i = a - 1; i >= 0; i--)
#define rrep2(i, a)      for(ll i = a - 1; i >= 0; i--)
#define rrep3(i, a, b)   for(ll i = a - 1; i >= b; i--)
#define rrep4(i, a, b, c) for(ll i = a - 1; i >= b; i -= c)
#define overload4_reverse(a, b, c, d, e, ...) e
#define rrep(...) overload4_reverse(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define INF ((1LL << 62) - (1LL << 31))
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007 //998244353
using mint = modint1000000007; //998244353
using ll = long long;
using vll = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
// ll dy[8] = {1,1,1,0,0,-1,-1,-1}, dx[8] = {1,0,-1,1,-1,1,0,-1};
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void YesNo(bool flag) { cout << (flag ? "Yes" : "No") << endl; }
void YESNO(bool flag) { cout << (flag ? "YES" : "NO") << endl; }
bool comp(int a, int b) { return a > b; } //降順
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b) { if (a > T(b)) { a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b) { if (a < T(b)) { a = b; return 1; } return 0; }
void in() {};
template <class T, class... U> void in(T&& x, U &&...y) { cin >> x; in(forward<U>(y)...); }
int print() { /*cout << '\n';*/ return 0; }
template <class head, class... tail> int print(head&& h, tail&&... t) { cout << h << (sizeof...(t) ? ' ' : '\n'); return print(forward<tail>(t)...); }
#define inll(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define instr(...) string __VA_ARGS__; in(__VA_ARGS__)
template <class T> int print(vector<T>& a, char sep = ' ') { for (auto& val : a) cout << val << (&val != &a.back() ? sep : '\n'); return 0; }
template <class T>int print(vector<vector<T>>& a) { for (auto& row : a) print(row); return 0; }
/*cout << fixed << setprecision(15); for double*/
template <class K, class V> int print(map<K, V>& m, char sep = ' ') { for (auto& p : m) cout << p.second << (&p != &*prev(m.end()) ? sep : '\n'); return 0; }
template <class T> int print(set<T>& s, char sep = ' ') { for (auto& val : s) cout << val << (&val != &*prev(s.end()) ? sep : '\n'); return 0; }
template <class T> int print(multiset<T>& ms, char sep = ' ') { for (auto& val : ms) cout << val << (&val != &*prev(ms.end()) ? sep : '\n'); return 0; }
#pragma endregion header

int main()
{
    inll(N);
    vvll G(N + 1);
    rep(i, N - 1) {
        inll(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll st;
    rep(i, 1, N + 1) {
        if (G[i].size() == 1) {
            st = G[i][0];
            break;
        }
    }
    queue<ll> que;
    vll dist(N + 1, INF);
    que.push(st);
    dist[st] = 0;
    multiset<ll> mulst;
    mulst.emplace(G[st].size());
    while (!que.empty()) {
        ll cu = que.front();
        que.pop();
        for (auto nx : G[cu]) {
            ll ndist = dist[cu] + 1;
            if (dist[nx] > ndist) {
                if (ndist % 3 == 0) {
                    mulst.emplace(G[nx].size());
                }
                dist[nx] = ndist;
                que.push(nx);
            }
        }
    }
    print(mulst);
    return 0;
}