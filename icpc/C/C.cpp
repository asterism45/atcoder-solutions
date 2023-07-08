#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int n;
int solve() {

    cin >> n;
    while (n > 0) {
        int input[n * n];
        int a[n * n];
        int b[n * n];
        int c[n * n];

        for (int i = 0; i < n * n; i++)
        {
            cin >> input[i];
            a[i] = i;
        }
        for (int i = 0; i < n * n; i++)
        {
            int x = i % n;
            int y = i / n;
            if ((x + y) % 2 == 0) {
                b[n - 1 - x + y * n] = a[i];
                continue;
            }
            int move = (x + y + 1) / 2;
            if (move > n / 2) {
                move = n - move;
            }
            if (x > y) {
                b[n - 1 - x + y * n] = a[i + move * (n - 1)];
            }
            else {
                b[n - 1 - x + y * n] = a[i - move * (n - 1)];
            }
        }

        for (int i = 0; i < n * n; i++)
        {
            int x = i % n;
            int y = i / n;
            if ((x + y) % 2 == 0) {
                c[i] = b[i];
                continue;
            }
            int move = (x + y + 1) / 2;
            if (move > n / 2) {
                move = n - move;
            }
            if (x > y) {
                c[i] = b[i + move * (n - 1)];
            }
            else {
                c[i] = b[i - move * (n - 1)];
            }
        }
        for (int i = 0; i < n * n; i++)
        {
            cout << input[c[i]];
            if (i % n != n - 1)
             cout << " ";
            if (i % n == n - 1) cout << endl;
        }
        cin >> n;
    }
}

int main() {
    solve();
}