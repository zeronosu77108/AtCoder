#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int _max = 0;
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        _max = max(_max, l);
        sum += l;
    }

    if (sum > 2*_max) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
