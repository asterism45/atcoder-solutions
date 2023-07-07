#pragma region header
#include <bits/stdc++.h>
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
using ll = long long;
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
bool comp(int a, int b) { return a > b; } //降順
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

// int getPriority(char op) {
//     switch (op) {
//     case '*':
//     case '/':
//         return 2;
//     case '+':
//     case '-':
//         return 1;
//     default:
//         return 0;
//     }
// }

// int parseNumber(const string& input, size_t& index) {
//     int number = 0;
//     while (index < input.size() && isdigit(input[index])) {
//         number = number * 10 + (input[index] - '0');
//         index++;
//     }
//     return number;
// }

// string infixToRPN(const string& input) {
//     stack<char> ops;
//     string rpn;
//     for (size_t i = 0; i < input.size(); ) {
//         if (isdigit(input[i])) {
//             int number = parseNumber(input, i);
//             rpn += to_string(number) + ' ';
//         }
//         else {
//             char op = input[i++];
//             if (op == '(') {
//                 ops.push(op);
//             }
//             else if (op == ')') {
//                 while (!ops.empty() && ops.top() != '(') {
//                     rpn += ops.top();
//                     rpn += ' ';
//                     ops.pop();
//                 }
//                 if (!ops.empty()) ops.pop(); // Pop '('
//             }
//             else {
//                 while (!ops.empty() && getPriority(op) <= getPriority(ops.top())) {
//                     rpn += ops.top();
//                     rpn += ' ';
//                     ops.pop();
//                 }
//                 ops.push(op);
//             }
//         }
//     }

//     while (!ops.empty()) {
//         rpn += ops.top();
//         rpn += ' ';
//         ops.pop();
//     }

//     return rpn;
// }

// int evaluateRPN(const string& rpn) {
//     stack<int> values;
//     for (size_t i = 0; i < rpn.size(); ) {
//         if (isdigit(rpn[i])) {
//             int number = parseNumber(rpn, i);
//             values.push(number);
//             i++; // Skip the space
//         }
//         else if (rpn[i] != ' ') {
//             int value2 = values.top(); values.pop();
//             int value1 = values.top(); values.pop();
//             switch (rpn[i]) {
//             case '+': values.push(value1 + value2); break;
//             case '-': values.push(value1 - value2); break;
//             case '*': values.push(value1 * value2); break;
//             case '/': values.push(value1 / value2); break;
//             }
//             i++; // Skip the operator
//         }
//         else {
//             i++; // Skip the space
//         }
//     }
//     return values.top();
// }

// int main() {
//     ll N;
//     cin >> N;
//     for (ll i = 0;i < N;i++) {
//         string input;
//         getline(cin, input);
//         string rpn = infixToRPN(input);
//         cout << evaluateRPN(rpn);
//         // cout << "RPN: " << rpn << endl;
//         // cout << "Evaluation result: " << evaluateRPN(rpn) << endl;
//     }
//     return 0;
// }


typedef string::const_iterator State;
class ParseError {};
int expression(State& begin);
int term(State& begin);
int factor(State& begin);
int number(State& begin);

// この関数は加算と減算を扱います。まず最初に項（term）を読み取り、それに続く'+'または'-'に続く項を
// それぞれ加算または減算します。'+'や'-'がなくなるまでこの操作を続けます。
int expression(State& begin) {
    int ret = term(begin);

    for (;;) {
        if (*begin == '+') {
            begin++;
            ret += term(begin);
        }
        else if (*begin == '-') {
            begin++;
            ret -= term(begin);
        }
        else {
            break;
        }
    }

    return ret;
}

// factor関数: この関数は、数値または括弧で囲まれた式を解析します。最初に現れる文字が'('ならば、
// 括弧で囲まれた部分をexpression関数を使って計算します。そうでない場合は、ただ単に数値を読み取ります。
int factor(State& begin) {
    if (*begin == '(') {
        begin++; // '('を飛ばす。
        int ret = expression(begin);
        begin++; // ')'を飛ばす
        return ret;
    }
    else {
        return number(begin);
    }
}

// この関数は乗算と除算の両方を扱います。最初に数値を読み取り、それに続く''または'/'に続く数値をそれぞれ
// 乗算または除算します。''や'/'がなくなるまでこの操作を続けます。
int term(State& begin) {
    int ret = number(begin);

    // この;;は、無限ループを意味する。
    for (;;) {
        if (*begin == '*') {
            begin++;
            ret *= factor(begin);
        }
        else if (*begin == '/') {
            begin++;
            ret /= factor(begin);
        }
        else {
            break;
        }
    }

    return ret;
}

// numberは、整数をパースしてその値を返す。
// パースとは、文字列を解析して、意味を持つデータに変換すること。
int number(State& begin) {
    int ret = 0;

    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }

    return ret;
}


int main(void) {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        print(s);


        State begin = s.begin();
        int ans = expression(begin);
        cout << ans << endl;
    }
    return 0;
}