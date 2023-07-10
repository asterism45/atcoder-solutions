/* 10進数の数を二進数に変換したときの
   一番後ろの１を０に変える
   以下は10進数を二進数に変換したときの
   含まれる１の数(__builtin_popcount())
   二の補数とANDしてXORする
*/
ll popcount(ll N)
{
    ll ans = 0;
    while (N > 0) {
        ans++;
        N ^= (N & -N); // here
    }
    return ans;
}

// 約数を列挙してvllで返す
vll enum_div(ll N) {
    vll res;
    rep_sqrt(i, 1, N) {
        if (N % i == 0) {
            p.pb(i);
            if (i * i != N)
                p.pb(N / i);
        }
    }
    sort(all(res));
    return res;
}

// 桁数数える
ll cntdig(const ll& N) {
    ll cnt = 1;
    while ((N /= 10) != 0)
        cnt++;
    return cnt;
}

// 素因数分解
// pairのfirstが素因数、secondが指数
vector<pair<ll, ll>> prime_fac(const ll& N) {
    vector<pair<ll, ll>> res;
    rep_sqrt(i, 2, N) {
        if (N % i == 0) {
            ll ex = 0;
            while (N % i == 0) {
                ex++;
                N /= i;
            }
            res.pb(mpa(i, ex));
        }
    }
    // 最後に残った数
    if (N != 1) res.push_back(mpa(N, 1));
}

// dfsを用いた全探索例（配列をglobal変数にする）以下はabc165 c の例
vll A(10);
ll res = 0;
void dfs(vll& a, vll& b, vll& c, vll& d, ll cu, ll num, ll N, ll Q, ll M) {
    if (cu == N) {
        //print(A);
        ll s = 0;
        rep(Q) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i])
                s += d[i];
        }
        chmax(res, s);
    }
    else {
        rep(i, num, M + 1) {
            A[cu] = i;
            //print("cu:", cu, "i:", i);
            dfs(a, b, c, d, cu + 1, i, N, Q, M);
        }
    }
}

// 3しんすうに変換
string toBase3(ll n) {
    string result = "";

    do {
        result += to_string(n % 3);
        n /= 3;
    } while (n > 0);

    reverse(result.begin(), result.end());
    return result;
}