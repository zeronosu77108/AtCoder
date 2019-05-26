#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

bool compare(vector<long long> i1, vector<long long> i2) 
{ 
    return (i1[1] > i2[1]); 
} 

int main() {
    long long n,m;
    vector<long long> a;
    vector<vector<long long> > bc;
    cin >> n >> m;

    for(long long i=0; i<n; i++) {
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for(long long i=0; i<m; i++) {
        long long tmp;
        vector<long long> vtmp;
        cin >> tmp;
        vtmp.push_back(tmp);
        cin >> tmp;
        vtmp.push_back(tmp);
        bc.push_back(vtmp);
    }
    
    sort(a.begin(), a.end());
    sort(bc.begin(), bc.end(), compare);

    // cout << endl;
    // for(long long i=0; i<n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl << endl;
    // for(long long i=0; i<m; i++) {
    //     cout << bc[i][0] << " " << bc[i][1] << endl;
    // }
    // cout << endl << endl;
    long long i,j;
    i = j = 0;

    while( a[i] < bc[j][1] ) {
        if( bc[j][0] > 0 ) {
            a[i] = bc[j][1];
            i++;
            if( i > n-1 ) {
                break;
            }
            bc[j][0]--;
        } else {
            j++;
            if( j > m-1 ) {
                break;
            }
        }
    }
    long long ans = 0;
    for(long long i=0; i<n; i++) ans += a[i];
    cout << ans << endl;
}
