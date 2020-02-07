#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> div = {0,0,0,0,0};

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a % 4 == 0) div[4]++;
        else if (a % 2 == 0) div[2]++;
        else div[0]++;
    }

    bool ans = false;
    ans = ans || div[2] == n;
    ans = ans || (div[2] == 0 && div[4] >= div[0] - 1);
    ans = ans || div[4] >= div[0];
//    ans = ans || (n == 3 && div[4]>=1);


    cout << (ans? "Yes" : "No") << endl;
}

/*
 * 1 4 1
 * 1 4 1
 * 1 4 1 4 2 2
 * 1 4 1 4 1
 */