#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans(n,0);
  vector<bool> f(n,false);

  for (int i=0; i<n; i++) {
    if (f[i]) continue;
    if(s[i] == 'R') {
      int cnt = 0;
      int ad = 0;

      while(i+cnt < n && s[i+cnt] != 'L') {
        if (cnt%2==0) {
          f[i+cnt] = true;
          ad++;
        }
        cnt++;
      }
      if (cnt%2 == 0) ans[i+cnt]+=ad;
      else ans[i+cnt-1]+=ad;

    }
  }

  for (int i=n-1; i>0; i--) {
    if (f[i]) continue;

    if (s[i] == 'L') {
      int cnt = 0;
      int ad = 0;
      while( i-cnt>0 && s[i-cnt] != 'R') {
        if (cnt%2 == 0) {
          f[i-cnt] = true;
          ad++;
        }
        cnt++;
      }
      if (cnt%2 == 0) ans[i-cnt]+=ad;
      else ans[i-cnt+1]+=ad;
    }
  }

  for (int i=0; i<n; i++) {
    printf("%d%c",ans[i],(i<n-1? ' ' : '\n'));
  }
}