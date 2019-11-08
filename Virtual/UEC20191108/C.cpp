#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


void dfs(int p, int u, int n,vector<bool>& used, vector<vector<int>>& g, int& ans) {
  if (n>2) return;
  if (p!=-1 && !used[u]) ans++;
  used[u] = true;
  // cout << "u ans " << u << " "<< ans << endl;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(u,v,n+1,used, g,ans);
  }
}

int main() {
  int n,m;
  int ans = 0;
  cin >> n >> m;
  vector<vector<int>> g(n+1);
  vector<bool> used(n+1,false);

  for (int i=0; i<m; i++) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(-1, 1,0,used,g,ans);

  cout << ans << endl;
}