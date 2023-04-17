#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
#include <iterator>

using namespace std;
using Graph = vector<vector<int>>;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, vector<vector<int>> &map, int count, int m, int n){
    int num = 0;
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < m && y + dy[i] < n && x + dx[i] > -1 && y + dy[i] > -1)
        {
            if (map[x + dx[i]][y + dy[i]] == 1)
            {
                map[x + dx[i]][y + dy[i]] = 0;
                num = max(num, dfs(x + dx[i], y + dy[i], map, count + 1, m, n));
            }
        } 
    }
    return max(num, count);
}



int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> map(90, vector<int>(90));
    vector<vector<int>> map2(90, vector<int>(90));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map.at(i).at(j);
        }
    }

    

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int s = 0; s < m; s++)
    {
        for (int t = 0; t < n; t++)
        {
            map2.at(s).at(t) = map.at(s).at(t);
        }
    }
            ans = max(ans, dfs(i, j, map2, 0, m, n));
        }
    }

    cout << ans << endl;
    
    return 0;
}


