#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    char pre = '*';
    bool ans = true;
    set<string> used;
    for (int i=0; i<n; i++) {
        string w;
        cin >> w;
        if (used.find(w) != used.end()) ans = false;
         used.insert(w);
        if (pre != '*' && w[0] != pre) ans = false;
        pre = w.back();
    }

    cout << (ans? "Yes" : "No") << endl;
}