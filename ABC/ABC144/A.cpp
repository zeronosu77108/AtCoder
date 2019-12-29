#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  cout << ((a<=9&&b<=9)? a*b : -1) << endl;
}