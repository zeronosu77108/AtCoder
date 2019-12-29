#include <iostream>

using namespace std;

int main() {
    long long r,d,x;
    cin >> r >> d >> x;
    
    for(long long i=0; i<10; i++) {
        cout << (x=r*x-d) << endl;
    }
}
