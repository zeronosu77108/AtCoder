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
    string s; cin>>s;
    bool ans = true;

    while(s.size() > 0) {
        if (s.back() == 'o' || s.back() == 'k' || s.back() == 'u') {
            s.pop_back();
        } else if (s[s.size()-2] == 'c' && s[s.size()-1] == 'h') {
            s.pop_back(); s.pop_back();
        } else {
            ans = false;
            break;
        }
    }

    cout << (ans? "YES" : "NO") << endl;
}