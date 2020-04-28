#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 a,b,k,l;
    cin >> a >> b >> k >> l;
    cout << min((k+l-1)/l * b, k/l*b + k%l*a) << endl;
}