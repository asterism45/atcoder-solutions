#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

int main()
{
    int T;
    cin >> T;
    vector<int> ans(T);

    rep(k, 0, T)
    {
        int N;
        cin >> N;

        string c;
        cin >> c;

        int count = 0;
        bool flag = true;
        int tmp = 0;

        rep(i, 0, N)
        {
            if (c[i] == '1' && flag){
                count++;
                tmp = i;
                flag = false;
            }
            else if(c[i] == '1')
                count++;
        }

        if (count % 2 == 1)
            ans[k] = -1;
        else
        {
            if (count == 2)
            {
                if (c[tmp + 1] == '1'){
                    if(c == "110" || c == "011" || c == "101")
                        ans[k] = -1;
                    else if(c == "0110")
                        ans[k] = 3;
                    else
                        ans[k] = 2;
                }
                else
                    ans[k] = 1;
            }
            else
                ans[k] = (count / 2);
        }
    }

    rep(k, 0, T)
        cout << ans[k] << endl;

    return 0;
}
