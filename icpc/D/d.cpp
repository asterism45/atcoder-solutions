#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int solve(int& N) {
    vector<int> p;
    rep(i, N + 1) {
        char x; cin >> x;
        if (x == 'o') p.push_back(i);
    }
    vector<int> now;
    for (auto x : p) {
        vector<int> dp(200);
        dp[0] = 1;
        for (auto nn : now) {
            for (int i = 110; i >= 0; i--) {
                if (i + nn <= 110) dp[i + nn] = max(dp[i + nn], dp[i]);
            }
        }
        if (dp[x]) continue;
        now.push_back(x);
    }
    cout << now.size() << endl;
}

int main() {
    while (true) {
        int N; cin >> N;
        if (N == 0) return 0;
        solve(N);
    }
}