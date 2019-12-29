#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>


using namespace std;

void dfs(int qi, int x, vector<vector<int>>& g, vector<long>& ans) {
  int a = ans[qi]+x;
  ans[qi] = a;
  x = a;
  for(auto v : g[qi] ) {
    dfs(v,x,g,ans);
  }
}

int main() {
  int n,q;
  cin >> n >> q;
  vector<vector<int>> g(n+1);
  vector<long> ans(n+1,0);

  for (int i=0; i<n-1; i++) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  for (int i=0; i<q; i++) {
    int qi,x;
    cin >> qi >> x;
    ans[qi] += x;
  }

  dfs(1,0,g,ans);

  for (int i=1; i<=n; i++) {
    cout << ans[i] << (i==n? '\n' : ' ');
  }
}