#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
  int n,k;
  string s;
  cin >> n >> k;
  cin >> s;
  int ans = 0;


  vector<int> con;
  if (s[0] == '0') con.push_back(0);
  for (int i=0; i<n; ) {
    int j=i;
    while(j<n && s[i]==s[j]) j++;
    con.push_back(j-i);
    i = j;
  }
  if (s.back() == '0') con.push_back(0);

  vector<int> sum(con.size()+1, 0);
  for (int i=0; i<con.size(); i++) sum[i+1] = sum[i] + con[i];

  for (int l=0; l<sum.size(); l+=2) {
    int r = l + k*2+1;
    if (r >= sum.size()) r = sum.size()-1;
    ans = max(ans, sum[r]-sum[l]);
  }

  cout << ans << endl;
}