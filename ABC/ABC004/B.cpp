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


int main() {
    char b[4][4];
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            cin >> b[i][j];

    for (int i=3; i>=0; i--) {
        for (int j=3; j>=0; j--)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}