#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    long n, coin[3];

    bool flag = false;

    cin >> n >> coin[0] >> coin[1] >> coin[2];

    sort(coin, coin + 3, greater<int>());

    int num1 = n / coin[0], num2 = 0, num3 = 0;
    int tmp;

    while ()
    {
        tmp = n - (coin[0] * num1);
        if(tmp == 0)
        {
            flag = true;
            break;
        }
        num2 = tmp / coin[1];
        while (!flag && num2 != 0)
        {
            tmp -= coin[1] * num2;
            if(tmp % coin[2] == 0)
            {
                flag = true;
            }
            num2--;
        }
        num1--;
    }

    cout << (num1 + num2 + num3);
    
}