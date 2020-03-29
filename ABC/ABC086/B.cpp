#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    int n = stoi(a+b);
    int r = sqrt(n);
    bool ans = n == r * r;
    cout << (ans? "Yes" : "No") << endl;
}