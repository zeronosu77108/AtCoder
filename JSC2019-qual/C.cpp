#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

const int mod = 1000000007;

long long frac(long long n) {
  if(n==1) return 1;
  return (n*frac(n-1))%mod;
}

int main() {
  int n;
  long long ans = 1;
  string s;
  cin >> n;
  cin >> s;
  n *= 2;
  vector<bool> cell(n);

  for (int i=0; i<n; i++) {
    cell[i] = (s[i] == 'B');
    if(!(i%2)) cell[i] = !cell[i];
    // cout << cell[i] << " ";
  } //cout << endl;

  int cnt = 0;
  for (int i=0; i<n; i++) {
    if(!cell[i]) cnt++;
    else {
      if(!cnt) {
        puts("0");
        return 0;
      }
      else {
        // cout << "*" << cnt << endl;
        ans *= cnt--;
      }
    }
    ans %= mod;
  }
  ans *= frac(n/2);
  ans %= mod;
  cout << (cnt ? 0 : ans) << endl;
}
