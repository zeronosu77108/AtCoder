#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n,t;
  cin >> n >> t;
  vector<int> tn(n);
  int ans = 0;

  for (int i=0; i<n; i++) cin>>tn[i]; // 逐次でも処理できそうなので保存しておく必要はない

  // お湯が止まる時刻より後なら，単純にt時間出ているのでそれを足す
  // そうじゃないなら，押される時刻までの差分を足す（もしかしてmod tとかでも良い？）
  int stop = tn[0] + t;
  for (int i=1; i<n; i++) {
    if (stop < tn[i] ) ans += t; 
    else ans += t - (stop - tn[i]);

    stop = tn[i] + t; // お湯の止まる時間の更新
  }

  cout << ans + t << endl;
}