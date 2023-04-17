#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

int main()
{
    int per[8] = {1,2,3,4,5,6,7,8};
    int n;
    cin >> n;
    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    for (int i = 0; i < n; i++)
        cin >> q[i];

    int count = 1;
    int a, b;

    do
    {
        int pflag = 1, qflag = 1;

        for (int i = 0; i < n; i++)
        {
            if (per[i] != p[i])
            {
                pflag = 0;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (per[i] != q[i])
            {
                qflag = 0;
                break;
            }
        }

        if(pflag){
            a = count;  
            pflag = 0;
        }
        if(qflag){
            b = count;
            qflag = 0;
        }

        count++;
        
    } while (next_permutation(per, per + n));
    
    int ans = abs(a - b);

    cout << ans;

    return 0;
}