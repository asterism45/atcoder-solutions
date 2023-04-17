#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
        for (int j = 0; j < c[i]; j++)
        {
            cin >> a.at(i).at(j);
        }
    }

    int count = 0;
    
    for (int bit = 0; bit < 1 << m; bit++)
    {
        vector<bool> flag(n, false);
        bool check = true;
        for (int i = 0; i < m; i++)
        {
            if (bit & 1 << i)
            {
                for (int j = 0; j < c[i]; j++)
                {
                    flag[a.at(i).at(j) - 1] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(flag[i] == false)
                check = false;
        }
        
        if (check)
        {
            count++;
        }
        
    }
    
    cout << count;

    return 0;
}