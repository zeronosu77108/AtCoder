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
    string s;
    cin >> s;
    int n = s.size();

    map<char, int> mp;
    for (int i=0; i<n; i++) mp[s[i]]++;

    for (char c='A'; c<='F'; c++) {
        cout << mp[c] << (c!='F'? " " : "\n");
    }
}