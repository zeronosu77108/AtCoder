#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;


int main() {
    vector<int> score(3);
    map<int,int> rank;
    for (int i=0; i<3; i++) cin>>score[i];
    vector<int> _score(3);
    _score = score;
    sort(score.rbegin(), score.rend());
    for (int i=0; i<3; i++) rank[score[i]] = i+1;

    for (int i=0; i<3; i++)
        cout << rank[_score[i]] << endl;
}