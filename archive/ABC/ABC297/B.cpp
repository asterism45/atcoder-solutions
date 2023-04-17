#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll A, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, S, T, U, W, X, Y, Z;
ll res, cnt = 0;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b)
{
  if (a % b == 0)
  {
    return b;
  }
  else
  {
    return gcd(b, a % b);
  }
}

int main()
{
    string S;
    cin >> S;
    vll b(2), r(2);
    ll k;
    ll x = 0, y = 0;
    rep(i,0,S.size()){
        if(S[i] == 'B'){
            b[x] = i + 1;
            x++;
        }
        else if(S[i] == 'R'){
            r[y] = i + 1;
            y++;
        }
        else if(S[i] == 'K'){
            k = i + 1;
        }
    }

    if(((b[0] % 2) != (b[1] % 2)) && (r[0] < k && k < r[1])){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
