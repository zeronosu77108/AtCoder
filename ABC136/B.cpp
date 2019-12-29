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
  int ans=0;

  for(int i=1; i<=n; i++) {
    if(to_string(i).length() %2 != 0) {
      ans++;
    }
  }
  cout << ans << endl;
}