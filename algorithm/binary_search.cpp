// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
  if (a[index] >= key)
    return true;
  else
    return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
  ll ng = -1;
  ll ok = (ll)a.size();

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(mid, key))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main() {
  cout << binary_search(51) << endl;  // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
  cout << binary_search(1) << endl;   // a[0] = 1
  cout << binary_search(910) << endl; // a[9] = 910

  cout << binary_search(52) << endl;  // 6
  cout << binary_search(0) << endl;   // 0
  cout << binary_search(911) << endl; // 10 (場外)
}