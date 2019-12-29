#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n,d;
  cin >> n >> d;
  cout << ceil(n/(2*d+1.0)) << endl;
}