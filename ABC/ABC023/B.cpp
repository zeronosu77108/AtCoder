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
    int ans = -1;
    string s;
    cin >> n >> s;
    bool f = true;
    map<char,char> mp;
    mp['a'] = 'b';
    mp['b'] = 'c';
    mp['c'] = 'a';

    if (n % 2 != 1) f = false;
    if (s[n/2] != 'b') f = false;
    for (int i=0; i<n-1; i++) {
        if (mp[s[i]] != s[i+1]) f =false;
    }

    cout << (f? (n-1)/2 : -1) << endl;
}