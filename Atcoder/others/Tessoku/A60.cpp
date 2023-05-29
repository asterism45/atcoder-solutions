#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define INF ((1LL << 62) - (1LL << 31))
#define mp make_pair
#define MOD 1000000007
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

int main()
{
    cin >> N;
    vector<pair<ll, ll>> A(N);
    rep(i, N) {
        A[i].first = i + 1;
        cin >> A[i].second;
    }
    stack<pair<ll, ll>> st;
    rep(i, N) {
        if (st.empty()) {
            cout << -1 << " ";
            st.push(A[i]);
        }
        else {
            ll f = 0;
            pair<ll, ll> pa = st.top();
            while (A[i].second >= pa.second) {
                st.pop();
                if (st.empty())
                    break;
                else
                    pa = st.top();
            }
            if (st.empty())
                cout << -1 << " ";
            else
                cout << pa.first << " ";
            st.push(A[i]);
        }
    }
    cout << endl;
    return 0;
}