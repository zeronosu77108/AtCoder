#include <iostream>
#include <cmath>

using namespace std;

float d(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    int x1,y1,r;
    cin >> x1 >> y1 >> r;
    int x2,y2,x3,y3;
    cin >> x2 >> y2 >> x3 >> y3;

    bool red = (x1-r<x2 || x3<x1+r) || (y1-r<y2 || y3<y1+r);
    bool blue = true;

    if (d(x1,y1,x2,y2) < r &&
        d(x1,y1,x2,y3) < r &&
        d(x1,y1,x3,y2) < r &&
        d(x1,y1,x3,y3) < r
    ) blue = false;

    cout << (red? "YES" : "NO") << endl;
    cout << (blue? "YES" : "NO") << endl;
}