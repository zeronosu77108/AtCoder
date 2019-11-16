#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int ans = a*x+b*y;
    ans = min(ans, c*2*x + (x>=y? 0 : (y-x)*b));
    ans = min(ans, c*2*y + (x<=y? 0 : (x-y)*a));

    cout << ans << endl;
}