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
#define MOD 998244353 //998244353
using mint = modint998244353; //998244353
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
template<class... T> constexpr auto min(T... a) { return min(initializer_list<common_type_t<T...>>{a...}); }
template<class... T> constexpr auto max(T... a) { return max(initializer_list<common_type_t<T...>>{a...}); }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b) { if (a > T(b)) { a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b) { if (a < T(b)) { a = b; return 1; } return 0; }
void in() {};
template <class T, class... U> void in(T&& x, U &&...y) { cin >> x; in(forward<U>(y)...); }
int print() { return 0; }
template <class head, class... tail> int print(head&& h, tail&&... t) { cout << h << (sizeof...(t) ? ' ' : '\n'); return print(forward<tail>(t)...); }
#define inll(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define instr(...) string __VA_ARGS__; in(__VA_ARGS__)
template <class T> int print(vector<T>& a, char sep = ' ') { for (auto& val : a) cout << val << (&val != &a.back() ? sep : '\n'); return 0; }
template <class T>int print(vector<vector<T>>& a) { for (auto& row : a) print(row); return 0; }
#pragma endregion header

int main()
{
  inll(Q);
  deque<ll> dig;
  dig.push_back(1);
  mint res = 1;
  while (Q-- > 0) {
    inll(A);
    if (A == 1) {
      inll(x);
      dig.push_back(x);
      res = res * 10 + x;
      //print(dig);
    }
    else if (A == 2) {
      res -= mint(10).pow(dig.size() - 1) * dig.front();
      dig.pop_front();
    }
    else {
      print(res.val());
    }
  }
  return 0;
}