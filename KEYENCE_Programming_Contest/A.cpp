#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> n;
    vector<int> v{1,4,7,9};
    int tn;

    for (int i=0; i<4; i++) {
        cin >> tn;
        n.push_back(tn);
    }
    sort(n.begin(), n.end());

    if ( n == v ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
