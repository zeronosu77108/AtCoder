#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    bool ans = true;

    if (s[0] != 'A') ans = false;
    for (int i=1; i<n; i++) {
        if (i>1 && i!=n-1 && s[i] == 'C') count++;
        else if (s[i]>='A' && s[i]<='Z') ans = false;
    }
    ans &= (count==1);

    cout << (ans? "AC" : "WA") << endl;
}