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
  string s,t;
  cin >> s >> t;

  int ans = 0;

  for (int i=0; i<3; i++)
    if (s[i] == t[i]) ans++;

  cout << ans << endl;
}