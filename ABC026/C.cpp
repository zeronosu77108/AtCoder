#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

void dfs(int u, vector<int>&ans, vector<vector<int>> g) {
  if(g[u].size() <= 0) {
    ans[u] = 1;
    return;
  }

  for (auto v : g[u]) {
    // cout << u << "->" << v << endl;
    dfs(v,ans,g);
  }

  if (g[u].size() == 1 ) {
    ans[u] = ans[g[u][0]]*2+1;
  } else {
    int b_max = -1;
    int b_min = INT_MAX;

    for (auto v : g[u]) {
      b_max = max(b_max, ans[v]);
      b_min = min(b_min, ans[v]);
    }
    ans[u] = (b_max + b_min + 1);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n+1);

  for (int i=2; i<=n; i++) {
    int b;
    cin >> b;
    g[b].push_back(i);
  }

  vector<int> ans(n+1);
  dfs(1,ans,g);

  // for (int i=1; i<=n; i++) {
  //   cout << ans[i] << " ";
  // } cout << endl;
  
  cout << ans[1] << endl;
}