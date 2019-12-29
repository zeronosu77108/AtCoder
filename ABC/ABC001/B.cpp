#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    double m;
    int ans = 0;
    cin >> m;
    m /= 1000;
    if (m < 0.1) ans = 0;
    else if (m <= 5) ans = m*10;
    else if (m <= 30) ans = m + 50;
    else if (m <= 70) ans = (m-30)/5 + 80;
    else ans = 89;

    printf("%02d\n",ans);
}