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
    int n;
    cin >> n;
    int n_bugs = 0;
    int par = 0;

    for (int i=0; i<n; i++) {
        int a; cin>>a;
        if (a!=0) par++;
        n_bugs += a;
    }

    cout << (int)ceil((double)n_bugs / par) << endl;
}