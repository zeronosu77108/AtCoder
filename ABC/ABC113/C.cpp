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
  cin >> n >> m;
  vector<int> p(m);
  vector<int> y(m);
  vector<vector<int>> c(n+1);

  for (int i=0; i<m; i++) {
    cin >> p[i] >> y[i];
    c[p[i]].push_back(y[i]);
  }

  for (int i=1; i<=n; i++) sort(c[i].begin(), c[i].end());

  for (int i=0; i<m; i++) {
    int pi = p[i];
    int rank = lower_bound(c[pi].begin(),c[pi].end(),y[i]) - c[pi].begin();
    printf("%06d%06d\n",pi, rank+1);
  }

}