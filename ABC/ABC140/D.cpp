#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>

using namespace std;

int main() {
  int n,k;
  int ans = 0;
  string s;
  cin >> n >> k;
  cin >> s;

  int start,i,cnt;
  start = i = cnt = 0;
  while(i<n) {
    char c = s[i];
    while(i<n && c==s[i]) i++;  
    cnt++;
    if (i<n && cnt < 2*k+1) continue;
    else ans += (i-start)-1;
    start = i;
  }
  cout << ans << endl;
}