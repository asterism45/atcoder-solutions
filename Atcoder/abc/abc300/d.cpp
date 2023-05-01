#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll pow6(ll k) {
    ll res = 1;
    for (ll i = 0; i < k; i++) {
        res = (res * 6) % MOD;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll k = 1; k * k * k * k * k < N; k++) {
        ll temp = N;
        ll cnt = 0;
        for (ll i = 0; i < k; i++) {
            cnt = (cnt + (temp - 1) / 6) % MOD;
            temp = (temp - 1) / 6 + 1;
        }
        ans = (ans + pow6(k) * cnt) % MOD;
    }
    cout << ans << endl;
    return 0;
}
