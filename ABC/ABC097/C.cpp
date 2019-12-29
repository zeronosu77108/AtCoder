#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <set>

using namespace std;

int main() {
  string s;
  int k;
  vector<string> sub;
  cin >> s >> k;
  int n = s.size();

  for (int i=0; i<n; i++) {
    for (int j=1; j<=k; j++) {
      sub.push_back( s.substr(i, j) );
    }
  }

  sort(sub.begin(), sub.end());
  sub.erase(unique(sub.begin(),sub.end()), sub.end());
  cout << sub[k-1] << endl;
}