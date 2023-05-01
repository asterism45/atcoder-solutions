#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31))
#define pb push_back
#define mp make_pair
#define MOD 998244353
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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// ∴ Fermatの小定理 a^(p-1) ≡ 1 (mod p)
// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
  return modpow(a, mod - 2, mod);
}

ll f = 1;
std::map<ll, ll> prime_f(ll n) {
  std::map<ll, ll> result;
  for (int i = 2; i * i <= n && i < 7; i++) {
    while (n % i == 0) {
      result[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    result[n]++;
    if (n >= 7)
      f = 0;
  }

  return result;
}

ll kaijou(ll n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * kaijou(n - 1) % MOD;
}

int main() {
  cin >> N;
  map<ll, ll> factors = prime_f(N);
  if (!f) {
    cout << 0 << endl;
    return 0;
  }
  vll fa(6, 0);
  for (const auto& factor : factors) {
    fa[factor.first] = factor.second;
  }
  /*for (const auto& out : fa) {
    cout << out << endl;
  }*/

  map<ll, ll> sixmemo, kaijomemo;
  ll res = 0;
  ll a = fa[2], b = fa[3], c = fa[5];
  rep(x, 0, b + 1) {
    rep(y, 0, (a - x) / 2 + 1) {
      ll tmp = 1;
      if (b - x < 0 || a - x - 2 * y < 0) continue;
      if (kaijomemo[a + b - x - y + c] == 0)
        kaijomemo[a + b - x - y + c] = kaijou(a + b - x - y + c);
      if (kaijomemo[c] == 0)
        kaijomemo[c] = kaijou(c);
      if (kaijomemo[x] == 0)
        kaijomemo[x] = kaijou(x);
      if (kaijomemo[y] == 0)
        kaijomemo[y] = kaijou(y);
      if (kaijomemo[b - x] == 0)
        kaijomemo[b - x] = kaijou(b - x);
      if (kaijomemo[a - x - 2 * y] == 0)
        kaijomemo[a - x - 2 * y] = kaijou(a - x - 2 * y);
      tmp = kaijomemo[a + b - x - y + c] * modinv(kaijomemo[c], MOD) % MOD * modinv(kaijomemo[x], MOD) % MOD * modinv(kaijomemo[y], MOD) % MOD * modinv(kaijomemo[b - x], MOD) % MOD * modinv(kaijomemo[a - x - 2 * y], MOD) % MOD;
      tmp = tmp * modinv(modpow(6, a + b + c - x - y, MOD), MOD) % MOD;
      res = (res + tmp) % MOD;
      if (res < 0) res += MOD;
    }
  }
  cout << res << endl;

  return 0;
}