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
  int n;
  cin >> n;
  long double ans=0;

  priority_queue<long double, vector<long double>, greater<long double>> v;

  for (int i=0; i<n; i++) {
    long double v_t;
    cin >> v_t;
    v.push(v_t);
  }

  while(v.size() > 1 ) {
    long double v1 = v.top(); v.pop();
    long double v2 = v.top(); v.pop();

    v.push((v1+v2)/2.0);
    // cout << v1 << " " << v2 << endl;
  }

  cout << v.top() << endl;
}