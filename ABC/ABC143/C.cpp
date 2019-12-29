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
  string s;
  cin >> n >> s;
  int ans = 0;
  char c = ' ';
  for (int i=0; i<n; i++) {
    if (c != s[i]) c=s[i],ans++;
  }

  cout << ans << endl;
}