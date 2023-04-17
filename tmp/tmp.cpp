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
    vector<int> a(5);
    a[3] = 2;
    cout << a[a.begin()] << endl;
    
    return 0;
}


