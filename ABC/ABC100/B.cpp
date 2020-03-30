#include <iostream>

using namespace std;

int main() {
    int d,n;
    cin >> d >> n;
    n += n == 100;
    for (int i=0; i<d; i++) n *= 100;
    cout << n << endl;
}