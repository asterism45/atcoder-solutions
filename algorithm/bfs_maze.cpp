#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> s[i][j];
    }
    
    vector<vector<char>> dist(h, vector<char>(w, -1));
    queue<pair<int, int>> que;

    dist[0][0] = 0;
    que.push(make_pair(0,0));

    while (!que.empty())
    {
        pair<int,int> yx;
        yx = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = yx.first + dy[i], next_x = yx.second + dx[i];
            if (next_y < h && next_y > -1 && next_x < w && next_x > -1)
            {
                if (s[next_y][next_x] == '#' || dist[next_y][next_x] != -1)
                    continue;
                dist[next_y][next_x] = dist[yx.first][yx.second] + 1;
                que.push(make_pair(next_y, next_x));
            }
        }
    }

    if (dist[h - 1][w - 1] == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    

    int count = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (dist[i][j] != -1 ||(dist[i][j] == -1 && s[i][j] == '.'))
                count++;
        }
    }

    if(count - (dist[h - 1][w - 1] + 1) < 0)
        cout << 0 << endl;
    else
        cout << (count - (dist[h - 1][w - 1] + 1)) << endl;

    return 0;
}


