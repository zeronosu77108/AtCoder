#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>


using namespace std;

int main(void) {
    int n,l;
    int eat = 999;
    int sum = 0;
    cin >> n >> l;

    for(int i=1; i<=n; i++) {
        sum += l + i - 1;
        if( abs(eat) > abs(l+i-1) ) {
            eat = l+i-1;
            // cout << eat << " ";
        }
    }
    // cout << endl;

    cout << sum - eat << endl;
}
