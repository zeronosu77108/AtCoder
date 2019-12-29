#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main() {
  int h,w;
  int ans = -1;
  cin >> h >> w;
  vector<string> s(h);
  vector< vector<int> > r(h, vector<int> (w));
  vector< vector<int> > l(h, vector<int> (w));
  vector< vector<int> > u(h, vector<int> (w));
  vector< vector<int> > b(h, vector<int> (w));

  for(int i=0; i<h; i++) {
    cin >> s[i];
  }

  for(int i=0; i<h; i++) {
    l[i][0] = (s[i][0]=='#'? 0 : 1);
    r[i][w-1] = (s[i][w-1]=='#'? 0 : 1);
  }

  for (int i=0; i<h; i++) {
    for (int j=1; j<w; j++) {
      if (s[i][j] == '#') l[i][j] = 0;
      else l[i][j] = l[i][j-1] + 1;
    }
  }

  for (int i=0; i<h; i++) {
    for (int j=w-2; j>=0; j--) {
      if (s[i][j] == '#') r[i][j] = 0;
      else r[i][j] = r[i][j+1] + 1;
    }
  }

  for(int i=0; i<w; i++) {
    u[0][i] = (s[0][i]=='#'? 0 : 1);
    b[h-1][i] = (s[h-1][i]=='#'? 0 : 1);
  }

  for (int i=0; i<w; i++) {
    for (int j=1; j<h; j++) {
      if (s[j][i] == '#') u[j][i] = 0;
      else u[j][i] = u[j-1][i] + 1;
    }
  }

  for (int i=0; i<w; i++) {
    for (int j=h-2; j>=0; j--) {
      if (s[j][i] == '#') b[j][i] = 0;
      else b[j][i] = b[j+1][i] + 1;
    }
  }

  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      // cout << l[i][j] << " " << r[i][j] << " " << u[i][j] << " " << b[i][j] << endl;
      ans = max(ans, l[i][j]+r[i][j]+u[i][j]+b[i][j]-3);
    }
    // cout << endl;
  }
  cout << ans << endl;
}

/*
4 6
#..#..
.....#
....#.
#.#...
*/
