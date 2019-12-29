#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  long long h,w;
  long long ans = INT_MAX;
  cin >> h >> w;

  if (h%3==0 || w%3==0) {
    puts("0");
    return 0;
  }


  long long s = (long long)h*w;
  {
    long long tmp_h = h;
    long long tmp_w = w;
    long double goal = (long long)h*w/3.0;

    long long preb = INT_MAX;
    long long sep_h = 0;
    for(long long i=1; i<=h; i++) {
      long long s1 = i*h;
      if (abs(goal-s1) < preb) {
        preb = (goal - s1);
        sep_h = i;
      }
    }
    long long s1 = sep_h * tmp_w;
    tmp_h -= sep_h;

    {
      long long s2 = round(tmp_w / 2.0) * tmp_h;
      long long s3 = s - s1 - s2;

      long long s_max = max(s1, max(s2, s3));
      long long s_min = min(s1, min(s2, s3));
      ans = min(ans, (s_max-s_min));
    }

    {
      long long s2 = round(tmp_w / 2.0) * tmp_h;
      long long s3 = s - s1 - s2;

      long long s_max = max(s1, max(s2, s3));
      long long s_min = min(s1, min(s2, s3));
      ans = min(ans, (s_max-s_min));
    }
  }


  cout << ans << endl;
}