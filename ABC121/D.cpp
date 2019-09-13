#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  long a,b;
  cin >> a >> b;
  long ans = 0;
  if (a%2) ans ^= a++;
  if (!(b%2)) ans ^= b--;
  long n = (b-a+1)/2;
  ans ^= n%2;

  cout << ans << endl;
}