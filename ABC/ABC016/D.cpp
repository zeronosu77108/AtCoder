#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;
typedef pair<int,int> P;

bool isAcross(int64 x1, int64 y1, int64 x2, int64 y2, int64 x3, int64 y3, int64 x4, int64 y4) {
    int64 ta = (x3-x4)*(y1-y3) + (y3-y4)*(x3-x1);
    int64 tb = (x3-x4)*(y2-y3) + (y3-y4)*(x3-x2);
    int64 tc = (x1-x2)*(y3-y1) + (y1-y2)*(x1-x3);
    int64 td = (x1-x2)*(y4-y1) + (y1-y2)*(x1-x4);
    return (ta*tb<0) && (tc*td<0);
}

int main() {
    int ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (isAcross(ax,ay,bx,by, x[i], y[i], x[(i+1)%n], y[(i+1)%n]))
            cnt++;
    }

    cout << cnt/2 + 1 << endl;
}