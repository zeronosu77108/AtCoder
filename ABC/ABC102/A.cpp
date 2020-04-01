#include <iostream>

using namespace std;

int gcd(int a, int b) {return b? gcd(b,a%b) : a;};
int lcm(int a, int b) {return a / gcd(a,b) * b;};

int main() {
    int n;
    cin >> n;
    cout << lcm(2,n) << endl;
}