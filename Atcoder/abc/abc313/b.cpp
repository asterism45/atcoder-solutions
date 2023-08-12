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
#define rep_sqrt(i, a, n) for(ll i = a; i * i <= n; i++)
#define rrep1(a)         for(ll i = a - 1; i >= 0; i--)
#define rrep2(i, a)      for(ll i = a - 1; i >= 0; i--)
#define rrep3(i, a, b)   for(ll i = a - 1; i >= b; i--)
#define rrep4(i, a, b, c) for(ll i = a - 1; i >= b; i -= c)
#define overload4_reverse(a, b, c, d, e, ...) e
#define rrep(...) overload4_reverse(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define INF ((1LL << 62) - (1LL << 31))
#define mpa make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007 //998244353
using mint = modint1000000007; //998244353
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using int128 = __int128_t;
using vll = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
// ll dy[8] = {1,1,1,0,0,-1,-1,-1}, dx[8] = {1,0,-1,1,-1,1,0,-1};
bool inrange(ll H, ll W, ll y, ll x) { return 0 <= y && y < H && 0 <= x && x < W; }
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void Yes(bool flag) { cout << (flag ? "Yes" : "No") << endl; }
void YES(bool flag) { cout << (flag ? "YES" : "NO") << endl; }
bool descending(ll a, ll b) { return a > b; } //降順
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b) { if (a > T(b)) { a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b) { if (a < T(b)) { a = b; return 1; } return 0; }
__int128_t string_to_int128(const string& s) { __int128_t res = 0; bool neg = s[0] == '-'; for (size_t i = neg ? 1 : 0; i < s.size(); ++i) res = res * 10 + (s[i] - '0'); return neg ? -res : res; }
void in() {};
template <class T, class... U> void in(T&& x, U &&...y) { cin >> x; in(forward<U>(y)...); }
int print() { /*cout << '\n';*/ return 0; }
void print_int128(__int128_t h) { string s; bool neg = h < 0; if (neg) h = -h; do { s = char(h % 10 + '0') + s; h /= 10; } while (h); if (neg) s = '-' + s; cout << s; }
template <class head, class... tail> int print(head&& h, tail&&... t) { if constexpr (is_same_v<decay_t<head>, __int128_t>) { print_int128(h); } else { cout << h; } cout << (sizeof...(t) ? ' ' : '\n'); return print(forward<tail>(t)...); }
#define inll(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define inld(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define instr(...) string __VA_ARGS__; in(__VA_ARGS__)
#define invll(vec,n) vll vec(n); rep(i, n) in(vec[i]);
#define invs(vec,n) vs vec(n); rep(i, n) in(vec[i]);
#define invvll(vec,h,w) vvll vec(h, vll(w)); rep(i, h) rep(j, w) in(vec[i][j]);
#define invvc(vec,h,w) vvc vec(h, vc(w)); rep(i, h) rep(j, w) in(vec[i][j]);
template <class T> int print(vector<T>& a, char sep = ' ') { for (auto& val : a) cout << val << (&val != &a.back() ? sep : '\n'); return 0; }
template <class T>int print(vector<vector<T>>& a) { for (auto& row : a) print(row); return 0; }
template <class K, class V> int print(map<K, V>& m, char sep = ' ') { for (auto& p : m) cout << p.second << (&p != &*prev(m.end()) ? sep : '\n'); return 0; }
template <class T> int print(set<T>& s, char sep = ' ') { for (auto& val : s) cout << val << (&val != &*prev(s.end()) ? sep : '\n'); return 0; }
template <class T> int print(multiset<T>& ms, char sep = ' ') { for (auto& val : ms) cout << val << (&val != &*prev(ms.end()) ? sep : '\n'); return 0; }
/*cout << fixed << setprecision(15); for double*/
#pragma endregion header

int main()
{
    inll(N, M);
    vvll G(N + 1);
    rep(M) {
        inll(A, B);
        G[A].pb(B);
    }

    rep(i, 1, N + 1) {
        // BFS のためのデータ構造
        vll dist(N + 1, -1); // 全頂点を「未訪問」に初期化
        queue<ll> que;

        dist[i] = 0;
        que.push(i); // 0 を橙色頂点にする

        while (!que.empty()) {
            ll v = que.front(); // キューから先頭頂点を取り出す
            que.pop();

            for (auto nv : G[v]) {
                if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        ll f = 1;
        rep(j, 1, N + 1) {
            if (dist[j] == -1) f = 0;
        }
        if (f) {
            print(i);
            return 0;
        }
    }
    print(-1);
    return 0;
}