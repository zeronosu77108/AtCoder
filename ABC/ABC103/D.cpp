#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int,int> P;

int main() {
  int n,m;
  int ans = 1;
  cin >> n >> m;
  vector<P> req(m);
  for (int i=0; i<m; i++) {
    int u,v;
    cin >> u >> v;
    req[i] = P(u,v);
  }

  sort(req.begin(), req.end());

  int l,r;
  l = INT_MIN;
  r = INT_MAX;
  for (auto re : req) {
    // cerr << r.first << " " << r.second << endl;
    l = max(l,re.first);
    if (l >= r) {

      r = INT_MAX;
    }
    r = min(r,re.second);
  }

  cout << ans << endl;
}
