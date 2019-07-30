#include <iostream>
#include <vector>  

using namespace std;

int main(void) {
    int l,n;
    int current = 0;
    int ans = 0;
    vector<int> x;

    cin >> l;  cin >> n;

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    int max = *max_element(x.begin(), x.end());
    int min = *min_element(x.begin(), x.end());

    while( !x.empty() ) { 
        if ( current < min ) {
            cout << "current < min" << endl;
            if ( min-current > (current + l -max) ) {
                ans += min - current;
                current = min;
                x.erase( find(x.begin(), x.end(), min));
                min = *min_element(x.begin(), x.end());
            } else {
                ans += current + (l - max);
                current = max;
                x.erase( find(x.begin(), x.end(), max));
                max = *max_element(x.begin(), x.end());
            }
        } else if( current > max ) {
            if ( current - max > (min+ l - current) ) {
                ans += current - max;
                current = max;
                x.erase( find(x.begin(), x.end(), max));
                max = *max_element(x.begin(), x.end());
            } else {
                ans += min + (l - current);
                current = min;
                x.erase( find(x.begin(), x.end(), min));
                min = *min_element(x.begin(), x.end());
            }
        } else {
            if ( current - min > max - current ) {
                ans += current - min;
                current = min;
                x.erase( find(x.begin(), x.end(), min));
                min = *min_element(x.begin(), x.end());
            } else {
                ans += max - current;
                current = max;
                x.erase( find(x.begin(), x.end(), max));
                max = *max_element(x.begin(), x.end());
            }
        }
        cout << "c = " << current << endl;
        cout << "a = " <<ans << endl;
        cout << endl;
    }
    cout << ans << endl;
}
