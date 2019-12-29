#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int k,x;
  cin >> k >> x;
  k--;

  for(int i=x-k; i<=x+k; i++) {
    cout << i << (i==x+k ? "\n" : " ");
  }
}