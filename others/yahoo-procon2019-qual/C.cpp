#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 k,a,b;
    cin >> k >> a >> b;

    cout << max(k+1, min(k,a) + (k-a+1)/2*(b-a) + (k-a+1)%2) << endl;
}
