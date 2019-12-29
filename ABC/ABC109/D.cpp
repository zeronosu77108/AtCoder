#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int> (w,0));
  vector<string> ans;

  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i=0; i<h; i++) {
    bool isodd = (accumulate(a[i].begin(),a[i].end(),0L) %2);
    for (int j=0; j<w; j++) {
      if (isodd && a[i][j]%2 && i+1<h ) {
        a[i+1][j]++;

        ans.push_back(
        to_string(i+1) + " " + to_string(j+1) + " " +
        to_string(i+2) + " " + to_string(j+1));
        isodd = false;
        continue;
      }

      if (a[i][j]%2 && j+1<w) {
        a[i][j+1]++;
        ans.push_back(
        to_string(i+1) + " " + to_string(j+1) + " " +
        to_string(i+1) + " " + to_string(j+2));
      }
    }

  }

  cout << ans.size() << endl;
  for (auto s : ans) {
    cout << s << endl;
  }
}