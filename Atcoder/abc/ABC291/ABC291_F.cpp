#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <math.h>
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int gcd(int a, int b)
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
    int N, M;
    cin >> N >> M;
    vector<string> S(N + 1);
    rep(i, 1, N + 1)
            cin >> S[i];

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N + 1);
    for (int i = 1; i < N + 1; ++i)
    {
        rep(j, 1, M + 1)
        {
            if (S[i].at(j) == '1' && i + j <= M)
            {
                G[i].push_back(i + j);
            }
        }
    }

    rep(k, 2, N)
    {
        // BFS のためのデータ構造
        vector<int> dist(N + 1, -1); // 全頂点を「未訪問」に初期化
        queue<int> que;

        // 初期条件 (頂点 0 を初期ノードとする)
        dist[1] = 0;
        que.push(1); // 0 を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty())
        {
            int v = que.front(); // キューから先頭頂点を取り出す
            que.pop();

            // v から辿れる頂点をすべて調べる
            for (int nv : G[v])
            {
                if (dist[nv] != -1)
                    continue; // すでに発見済みの頂点は探索しない

                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                if (k != nv)
                {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
            }
        }
    }

    cout << "hhh" << endl;

    return 0;
}
