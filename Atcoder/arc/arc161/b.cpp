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
#define mpa make_pair
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

ll solve(ll N) {
    ll t = N, sum = 0;
    while (t > 0) {
        sum++;
        t ^= t & -t;
    }
    if (N < 7) return -1;
    else if (sum > 3)
        return solve(N ^ (N & -N));
    else if (sum == 3)
        return N;
    else
        return solve(N - 1);
}

int main() {
    inll(T);
    while (T-- > 0) {
        inll(N);
        print(solve(N));
    }
    return 0;
}


/*
int main()
{
    inll(T);
    while (T-- > 0) {
        inll(N);
        bitset<63> bi(N);
        ll num = bi.count();
        //print(bi);
        //print(bi.to_ullong());
        if (N < 7) {
            print(-1);
        }
        else {
            //ok
            if (num >= 3) {
                ll cnt = 0;
                rrep(i, bi.size()) {
                    if (bi[i] && cnt < 3) {
                        cnt++;
                    }
                    else if (bi[i] && cnt >= 3) {
                        bi[i] = 0;
                    }
                }
                print(bi.to_ullong());
            }
            else if (num == 2) {
                if (bi[0] == 1) {
                    bi[0] = 0;
                    ll i = 63;
                    while (bi[i] == 0) {
                        i--;
                    }
                    bi[i] = 0;
                    bi[--i] = 1;
                    bi[--i] = 1;
                    bi[--i] = 1;
                    print(bi.to_ullong());
                }
                else if (bi[1] == 1) {
                    bi[1] = 0;
                    ll i = 63;
                    while (bi[i] == 0) {
                        i--;
                    }
                    bi[i] = 0;
                    bi[--i] = 1;
                    bi[--i] = 1;
                    bi[--i] = 1;
                    print(bi.to_ullong());
                }
                else {
                    ll cnt = 0;
                    rrep(i, bi.size()) {
                        if (bi[i] == 1 && cnt == 0) {
                            cnt++;
                        }
                        else if (bi[i] == 1 && cnt == 1) {
                            bi[i] = 0;
                            bi[--i] = 1;
                            bi[--i] = 1;
                            break;
                        }
                    }
                    print(bi.to_ullong());
                }
            }
            //ok
            else {
                ll i = 63;
                while (bi[i] == 0) {
                    i--;
                }
                bi[i] = 0;
                bi[--i] = 1;
                bi[--i] = 1;
                bi[--i] = 1;
                print(bi.to_ullong());
            }
        }
    }


    return 0;
}
*/