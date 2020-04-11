#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 a,b,c,k;
    cin >> a >> b >> c >> k;

    cout << (k%2? b-a : a-b) << endl;
    return 0;
}
