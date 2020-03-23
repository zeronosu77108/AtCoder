#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

vector<int64> _ryuka(90,-1);

int64 ryuka(int n) {
    if (_ryuka[n] != -1) return _ryuka[n];
    return _ryuka[n] = ryuka(n-1) + ryuka(n-2);
}


int main() {
    int n;
    cin >> n;
    _ryuka[0] = 2;
    _ryuka[1] = 1;

    cout << ryuka(n) << endl;
}