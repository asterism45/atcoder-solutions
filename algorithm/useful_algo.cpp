/* 10進数の数を二進数に変換したときの
   一番後ろの１を０に変える
   以下は10進数を二進数に変換したときの
   含まれる１の数(__builtin_popcount())
   二の補数とANDしてXORする
*/
ll popcount(ll N)
{
    ll ans = 0;
    while (N > 0) {
        ans++;
        N ^= (N & -N); // here
    }
    return ans;
}