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

const int mod = 1000000007;
int64 gcd(int64 a,int64 b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    int64 a,b;
    cin >> a >> b;
    int64 GCD = gcd(a,b);
    int64 ans = a*b/GCD;
    cout << ans << endl;
}