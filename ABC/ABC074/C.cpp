#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;
int main() {
    int64 a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100;
    b *= 100;

    vector<int64> water;
    for (int64 i=0; i*a<=f; i++) {
        int64 aw = i*a;
        for (int64 j=0; j*b<=f; j++) {
            water.push_back(aw + j*b);
        }
    }

    vector<int64> sugar;
    for (int64 i=0; i*c<=f; i++) {
        for (int64 j=0; j*d<=f; j++) {
            sugar.push_back(i*c + j*d);
        }
    }

    double con = 0;
    int64 water_ans = 0;
    int64 sugar_ans = 0;
    for (auto w : water) {
        for (auto s : sugar) {
            if (w + s > f) continue;
            if (w/(double)100*e < s) continue;
            double c = 100 * s / (double)(w+s);
            if (c + 1e-14 > con) {  // 丸め誤差が発生するので 1e-14 を足して判定
                con = c;
                water_ans = w;
                sugar_ans = s;
            }
        }
    }

    cout << water_ans + sugar_ans << " " << sugar_ans << endl;
}