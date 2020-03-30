#include <iostream>

using namespace std;

int main() {
    int a,b,k;
    cin >> a >> b >> k;
    for (int i=a; i<=min(a+k-1,b); i++) cout << i << endl;
    for (int i=max(b-k+1,a+k); i<=b; i++) cout << i << endl;
}