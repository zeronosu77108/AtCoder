#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  int p0,p1,p2;
  int count=0;

  cin >> n;
  cin >> p0 >> p1;
  for(int i=0; i<n-2; i++) {
    cin >> p2;
    if(p0<p1 && p1<p2) count++;
    if(p0>p1 && p1>p2) count++;
    p0=p1; p1=p2;
  }
  cout << count << endl;
}