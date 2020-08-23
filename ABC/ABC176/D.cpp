#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <cstdio>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;

int main() {
    int h,w,ch,cw,dh,dw;
    scanf("%d %d %d %d %d %d",&h, &w,&ch,&cw,&dh,&dw);

    char s[h+1][w+1];
    for (int i=0; i<h; i++) {
        scanf("%s",s[i]);
    }

    vector num(h, vector(w,-1));

    const vector dx = {-1,0,+1,0};
    const vector dy = {0,+1,0,-1};

    deque<TP> q;
    q.emplace_back(0, ch-1,cw-1);
    while(!q.empty()) {
        auto [c,y,x] = q.front(); q.pop_front();
        if (x<0 || w<=x) continue;
        if (y<0 || h<=y) continue;
        if (s[y][x] == '#') continue;
        if (num[y][x]>=0 && num[y][x]<=c) continue;
        num[y][x] = c;


        for (short i=0; i<4; i++) {
            const int xi = x + dx[i];
            const int yi = y + dy[i];
            q.emplace_front(c,yi,xi);
        }

        for (short i=-2; i <=2; i++) {
            for (short j=-2; j<=2; j++) {
                const int xi = x + j;
                const int yi = y + i;
                q.emplace_back(c+1,yi, xi);
            }
        }
    }


    cout << num[dh-1][dw-1] << endl;
}