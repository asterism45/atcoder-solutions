#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define all(a) (a).begin(), (a).end()
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

bool isok(vector<vector<char>> &x, vector<vector<char>> &y) {
  ll f = 1;
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (x[i][j] != y[i][j]) f = 0;
    }
  }
  return f;
}

int main() {
  cin >> H >> W;
  ll f = 0;
  vector<vector<char>> A(H, vector<char>(W)), B(H, vector<char>(W)), C(H, vector<char>(W));
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> A[i][j];
    }
  }
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> B[i][j];
    }
  }

  rep(p, 0, H + 1) {
    rep(i, 0, H) {
      rep(j, 0, W) {
        if (i != H - 1)
          C[i][j] = A[i + 1][j];
        else
          C[i][j] = A[0][j];
      }
    }
    rep(i, 0, H) {
      rep(j, 0, W) {
        A[i][j] = C[i][j];
        //cout << A[i][j];
      }
      //cout << endl;
    }
    rep(q, 0, W) {
      if (isok(A, B)) f = 1;
      rep(i, 0, H) {
        rep(j, 0, W) {
          if (j != W - 1)
            C[i][j] = A[i][j + 1];
          else
            C[i][j] = A[i][0];
        }
      }
      rep(i, 0, H) {
        rep(j, 0, W) {
          A[i][j] = C[i][j];
        }
      }
    }
  }

  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}