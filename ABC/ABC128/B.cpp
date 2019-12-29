#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;


int main(void) {
    long n;
    vector< pair<string, int> > ass;
    cin >> n;

    for (long i=0; i<n; i++) {
        pair<string, int> tmp;
        cin >> tmp.first >> tmp.second;
        ass.push_back(tmp);
    }

    vector<int> index(ass.size());
    iota(index.begin(), index.end(), 0);


    sort(index.begin(),
         index.end(),
             [&](long x, long y){if( ass[x].first != ass[y].first) return ass[x].first<ass[y].first; return ass[x].second>ass[y].second;}
    );

    sort(ass.begin(), ass.end());

    // for (long i=0; i<n; i++) {
    //     cout << ass[i].first << " "<< ass[i].second << endl;
    // }

    for(auto i: index){
        cout << i+1 << endl;
    }
}
