#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int digit(int n) {
    int res = 0;
    while(n>0) {
        res++;
        n/= 10;
    }
    return res;
}

int main() {
    long a,b,x;
    cin >> a >> b >> x;

    long l,r;
    l = 0;
    r = 1e9+1;

    while(l+1 < r) {
        long g = (l+r)/2;
        bool f = true;
        if (a*g + b*digit(g) > x) f = false;
        (f? l : r) = g;
    }

    cout << l << endl;
}