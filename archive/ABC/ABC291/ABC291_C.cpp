#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}


int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    map<pair<int,int>, bool> m1;
    int x = 0, y = 0;
    m1[make_pair(0,0)] = 1;

    rep(i,0,S.size()){
        switch (S[i])
        {
        case 'R':
            x++;
            if(m1[make_pair(x,y)] != 0){
                cout << "Yes" << endl;
                return 0;
            }
            else{
                m1[make_pair(x,y)] = 1;
            }
            break;
        case 'L':
            x--;
            if(m1[make_pair(x,y)] != 0){
                cout << "Yes" << endl;
                return 0;
            }
            else{
                m1[make_pair(x,y)] = 1;
            }
            break;
        case 'U':
            y++;
            if(m1[make_pair(x,y)] != 0){
                cout << "Yes" << endl;
                return 0;
            }
            else{
                m1[make_pair(x,y)] = 1;
            }
            break;
        case 'D':
            y--;
            if(m1[make_pair(x,y)] != 0){
                cout << "Yes" << endl;
                return 0;
            }
            else{
                m1[make_pair(x,y)] = 1;
            }
            break;
        
        default:
            break;
        }
    }
    
    cout << "No" << endl;
    
    return 0;
}


