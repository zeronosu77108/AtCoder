#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;


vector<long> z_algorithm(const std::string& s, const long n){
  std::vector<long> z(n, 0);
  long L=0, R=0;
  for (long i=1; i<n; i++){
    if(i>R) {
      L = R = i;
      while(R<n && s[R-L]==s[R]) R++;
      z[i] = R-L;
      R--;
    } else {
      long k = i-L;
      if(z[k] < R-i+1){
        z[i] = z[k];
      } else {
        L = i;
        while(R<n && s[R-L]==s[R]) R++;
        z[i] = R-L; R--;
      }
    }
  }
  return z;
}

int main() {
  int n;
  long ans = 0;
  string s;
  cin >> n >> s;

  vector<long> z;
  for (int i=0; i<n-1; i++) {
    z = z_algorithm( s.substr(i, n-i), n-i);
    for (long j=1; j<n-i; j++) {
      ans = max(ans, min(z[j],j));
    }
  }

  cout << ans << endl;
}