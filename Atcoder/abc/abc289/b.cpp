#pragma region header
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
using vs = vector<string>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }
void outp(bool flag) { cout << (flag ? "Yes" : "No") << endl; }
bool comp(int a, int b) { return a > b; } //降順
template<class... T>
constexpr auto min(T... a) { return min(initializer_list<common_type_t<T...>>{a...}); }
void in() {};
template <class T, class... U>
void in(T&& x, U &&...y) { cin >> x; in(forward<U>(y)...); }
int print() { cout << '\n'; return 0; }
template <class head, class... tail>
int print(head&& h, tail&&... t) {
    cout << h << (sizeof...(t) ? ' ' : '\n');
    return print(forward<tail>(t)...);
}
#define inll(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define instr(...) string __VA_ARGS__; in(__VA_ARGS__)
template <class T>
int print(vector<T>& a, char sep = ' ') {
    for (auto& val : a)
        cout << val << (&val != &a.back() ? sep : '\n');
    return 0;
}
template <class T>
int print(vector<vector<T>>& a) {
    for (auto& row : a) print(row);
    return 0;
}
#pragma endregion header

int main()
{
    inll(N, M);
    vll f(N);
    rep(i, M) {
        inll(a);
        f[--a] = 1;
    }
    vll res;
    ll i = 0;
    while (i < N) {
        if (f[i]) {
            vll st;
            while (f[i]) {
                st.push_back(i + 1);
                i++;
            }
            st.push_back(i + 1);
            i++;
            reverse(all(st));
            for (auto s : st)
                res.push_back(s);
        }
        else {
            res.push_back(i + 1);
            i++;
        }
    }
    print(res);
    return 0;
}