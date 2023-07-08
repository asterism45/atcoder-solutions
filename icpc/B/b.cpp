#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int n, m, p, q;

int dfs(int k, vector<int>& now, vector<int>& A, bool flag) {
    if (k == m) {
        int id = 0;
        rep(i, n) if (now[i] == p) {
            id = i;
            break;
        }
        if (id == q && flag) return 1;

        if (id == q && !flag) return 2;
        return 0;
    }

    if (!flag) {
        int id = 0;
        rep(i, n) if (now[i] == p) {
            id = i;
            break;
        }
        if (id != 0) {
            swap(now[id - 1], now[id]);
            int ret = dfs(k, now, A, true);
            swap(now[id - 1], now[id]);
            if (ret == 1) {
                cout << id << " " << k << endl;
                return 1;
            }
            if (ret == 2) return 2;

        }
        if (id != n - 1) {
            swap(now[id + 1], now[id]);
            int ret = dfs(k, now, A, true);
            swap(now[id + 1], now[id]);
            if (ret == 1) {
                cout << id + 1 << " " << k << endl;
                return 1;
            }
            if (ret == 2) return 2;

        }
    }
    swap(now[A[k]], now[A[k] + 1]);
    int ret = dfs(k + 1, now, A, flag);
    swap(now[A[k]], now[A[k] + 1]);
    return ret;
}

int solve(int& n, int& m, int& p, int& q) {
    vector<int> A(m); rep(i, m) cin >> A[i];
    rep(i, m) A[i]--;
    // rep(i, m) cout << A[i] << " \n"[i == m - 1];
    vector<int> now(n); rep(i, n) now[i] = i;
    int ret = dfs(0, now, A, false);
    if (ret == 2) cout << "OK" << endl;
    if (ret == 0) cout << "NG" << endl;
}

int main() {
    while (true) {
        cin >> n >> m >> p >> q;
        if (n == 0) return 0;
        p--; q--;
        solve(n, m, p, q);
    }
}