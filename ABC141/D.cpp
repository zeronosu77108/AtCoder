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
  int n,m;
  cin >> n >> m;
  priority_queue<long> q;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    q.push(a);
  }

  for (int i=0; i<m; i++) {
    int a = q.top();
    q.pop();
    // cerr << a << " " << (int)((double)a/2.0) << endl;
    q.push((int)((double)a/2.0));
  }

  long ans = 0;
  while(! q.empty()) {
    ans += q.top();
    q.pop();
  }

  cout << ans << endl;
}