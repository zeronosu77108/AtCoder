#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <utility>


using namespace std;

void dfs(int root,int i, int count){
    if ( visited[i] ) return;
    visited[i] = true;
    for (int j=0; j<n; j++) {
        if( ad[i][j] > 0 ) {
            dfs(j);
        }
    }
}

int n;
long ad[110][110];
bool visited[110];

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        visited[i] = false;
        for(int j=0; j<n; j++)
            ad[i][j] = 0;

    for (int i=0; i<n; i++) {
        int u,v;
        cin >> u >> v;
        ad[u-1][v-1] = ad[v-1][u-1] = 1;
    }

    for (int i=0; i<n; i++) {
        dfs(i);
    }
}
