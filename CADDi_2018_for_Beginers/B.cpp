#include <iostream>

using namespace std;

int main(void) {
    int n,h,w;
    int count;

    cin >> n;  cin >> h;  cin >> w;
    for(int i=0; i<n; i++) {
        int a,b;
        cin >> a; cin >> b;
        if( h <= a && w <= b ) {
            count++;
        }
    }
    cout << count << endl;
}
