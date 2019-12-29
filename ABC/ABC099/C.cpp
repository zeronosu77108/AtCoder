#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = n;

  for (int i=0; i<=n; i++) {
    int cnt = 0;
    int tmp = i;

    while (tmp>0) cnt+=tmp%6, tmp/=6;
    tmp = n-i;
    while (tmp>0) cnt+=tmp%9, tmp/=9;

    ans = min(ans,cnt);
  }

  cout << ans << endl;
}