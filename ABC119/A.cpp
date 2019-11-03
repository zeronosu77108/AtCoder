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
    int y,m,d;
    scanf("%d/%d/%d",&y,&m,&d);
    string ans = "Heisei";
    if (y>2019 || (y==2019&&m>4) ) ans = "TBD";

    cout << ans << endl;
}