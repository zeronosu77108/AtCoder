#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

using int64 = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;

struct edge {
    long u,v,cost;
    edge(long _u, long _v, long _cost): u(_u), v(_v), cost(_cost){}
};

class unionfind {
    vector<int64> _size;
    vector<int64> _root;
public:
    unionfind(int n) {
        _size = vector<int64> (n+1, 1);
        _root = vector<int64> (n+1);
        iota(_root.begin(), _root.end(), 0);
    }
    int64 root(int x) {
        while(x != _root[x]) x = _root[x] = _root[_root[x]];
        return x;
    }
    bool merge(int x, int y) {
        if (is_same(x,y)) return false;
        x = root(x); y = root(y);
        if (_size[x] > _size[y]) swap(x,y);
        _size[y] += _size[x];
        _root[x] = y;
        return true;
    }
    int64 is_same(int x, int y) {
        return root(x) == root(y);
    }
    int64 size(int x) {
        return _size[root(x)];
    }
};

int64 kruskal(const int& n,vector<edge>& edges) {

    auto cmp = [](edge x, edge y) {return x.cost < y.cost;};
    sort(edges.begin(), edges.end(), cmp);
    unionfind uni(n);
    int res = 0;
    for (auto e : edges) {
        if (uni.is_same(e.u , e.v)) continue;
        uni.merge(e.u, e.v);
        res += e.cost;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<TP> p;
    for (int i=1; i<=n; i++) {
        int x,y;
        cin >> x >> y;
        p.emplace_back(x, y, i);
    }


    sort(p.begin(), p.end());

    vector<edge> edges;
    for (int i=0; i<n-1; i++) {
        int x1,y1,u;
        tie(x1, y1, u) = p[i];
        int x2,y2,v;
        tie(x2, y2, v) = p[i+1];
        edges.emplace_back(u,v, abs(x1 - x2));
    }

    auto cmp = [](TP x, TP y) {return get<1>(x) < get<1>(y);};
    sort(p.begin(), p.end(), cmp);

    for (int i=0; i<n-1; i++) {
        int x1,y1,u;
        tie(x1, y1, u) = p[i];
        int x2,y2,v;
        tie(x2, y2, v) = p[i+1];
        edges.emplace_back(u, v, abs(y1 - y2));

    }


    int ans = kruskal(n, edges);

    cout << ans << endl;

}