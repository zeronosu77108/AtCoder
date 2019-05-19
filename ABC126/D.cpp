#include <iostream>

using namespace std;

int main(void) {
    int n;
    int ans[100010];
    bool f[100010];
    for (int i=0; i<10000; i++) {
        f[i] = false; ans[i] = 1;
    }

    int u[100010],v[100010],w[100010];
    
    cin >> n;
    
    for (int i=0; i<n-1; i++) {
        cin >> u[i] >> v[i] >> w[i];
        if (w[i]%2 == 0) {
            f[u[i]-1] = true;
            f[v[i]-1] = true;
        } else {
            if ( ans[u[i]-1] != -1 && ans[v[i]-1] != -1 ) {
                if ( ! f[u[i]-1] ) {
                    ans[u[i]-1] = 0;
                } else if ( ! f[v[i]-1] ) {
                    ans[v[i]-1] = 0;
                } 
            }
        }

    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << endl;
    }
}

