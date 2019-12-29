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
  string s,t;
  cin >> t >> s;
  vector<vector<long>> tc(26);

  long n = t.size();
  for (long i=0; i<n; i++) {
    // cout << t[i] << " " << t[i] - 'a' << endl;
    tc[t[i]-'a'].push_back(i);
  }

  n = s.size();
  long cnt = 0;
  long m = -1;
  vector<vector<long>> ntc = tc;
  for (long i=0; i<n; i++) {

    if( tc[s[i]-'a'].size() <= 0 ) {
      cout << -1 << endl;
      return 0;
    }
    bool flag = false;
    int ind = s[i]-'a';
    auto it = upper_bound(tc[ind].begin(), tc[ind].end(), m);
    if (it != tc[ind].end() ){
      flag = true;
      m = *it;
    }

    if (!flag) {
      cnt++;
      m = tc[s[i]-'a'][0];
    }
  }
    
  // cout << cnt << " " << m << endl;
  cout << (long long)t.size()*cnt + m + 1 << endl;

}