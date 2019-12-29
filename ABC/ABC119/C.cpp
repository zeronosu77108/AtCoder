#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int A,B,C;
void dfs(const int n, const int a, const int b, const int c, const int count, int& ans, const vector<int>& l) {
  if (n<0) {
    if (a==0 || b==0 || c==0) return;
    ans = min(ans, abs(A-a) + abs(B-b) + abs(C-c) + count*10);
    return;
  }

  dfs(n-1,a,b,c,count,ans,l);
  dfs(n-1,a+l[n],b,c,(a>0? count+1 : count),ans,l);
  dfs(n-1,a,b+l[n],c,(b>0? count+1 : count),ans,l);
  dfs(n-1,a,b,c+l[n],(c>0? count+1 : count),ans,l);
}

int main() {
  int n;
  cin >> n >> A >> B >> C;
  vector<int> l(n);
  for (int i=0; i<n; i++) cin>>l[i];

  int ans = INT_MAX;
  dfs(n-1,0,0,0,0,ans,l);

  cout << ans << endl;
}