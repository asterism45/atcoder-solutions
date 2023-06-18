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
    inll(N, K, Q);
    vll A(N, 0), f(N, 0);
    ll cnt = 0;
    ll res = 0;
    multiset<pair<ll, ll>> use, nuse;
    while (Q-- > 0)
    {
        inll(X, Y);
        X--;
        if (f[X]) { // 使ってる
            res -= A[X];
            //print("check:", res);
            use.erase(mpa(A[X], X));
            if (nuse.size() == 0) {
                //print("case0");
                res += Y;
                use.insert(mpa(Y, X));
            }
            else {
                auto ma = *(--nuse.end());
                if (ma.first > Y) {
                    //print("case1");
                    nuse.erase(ma);
                    use.insert(ma);
                    nuse.insert(mpa(Y, X));
                    f[X] = 0;
                    f[ma.second] = 1;
                    res += ma.first;
                }
                else {
                    //print("case2");
                    res += Y;
                    use.insert(mpa(Y, X));
                }
            }
        }
        else {
            if (use.size() < K) {
                //print("case3");
                use.insert(mpa(Y, X));
                if (A[X] != 0) {
                    nuse.erase(mpa(A[X], X));
                }
                res += Y;
                f[X] = 1;
            }
            else {
                auto t = *use.begin();
                if (t.first < Y) {
                    //print("case4");
                    auto mi = *use.begin();
                    use.erase(mi);
                    nuse.insert(mi);
                    use.insert(mpa(Y, X));
                    if (A[X] != 0) {
                        nuse.erase(mpa(A[X], X));
                    }
                    res += Y;
                    res -= mi.first;
                    f[X] = 1;
                    f[mi.second] = 0;
                }
                else {
                    //print("case5");
                    if (A[X] != 0) {
                        nuse.erase(mpa(A[X], X));
                    }
                    nuse.insert(mpa(Y, X));
                }
            }
        }
        A[X] = Y;
        //print(use.size(), nuse.size());
        print(res);
    }

    return 0;
}