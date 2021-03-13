//
// Created by zeronosu77108 on Mar 13, 2021.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>
#include <optional>



// Ford-Fulkerson
template <class T> class MaxFlow {
    const int n;
    std::vector<std::vector<std::tuple<int, int, T>>> graph;
public:
    explicit MaxFlow(const int _n) : n(_n+1), graph(_n+1) {}
    void add_edge(int from, int to, T cap) {
        graph[from].emplace_back(to, graph[to].size(), cap);
        graph[to].emplace_back(from, graph[from].size()-1, 0);
    }

    T dfs(int v, int t, T f, std::vector<bool>& visited) {
        if (v == t) return f;
        visited[v] = true;

        for (auto& [u, rev, cap] : graph[v]) {
            if (!visited[u] && cap > 0) {
                T d = dfs(u, t, std::min(f, cap), visited);
                if (d > 0) {
                    cap -= d;
                    auto& [_,__,rev_cap] = graph[u][rev]; rev_cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while(true) {
            std::vector<bool> visited(n);
            if (T f=dfs(s,t,INT_MAX, visited); f==0) return flow;
            else flow += f;
        }
    }
};



int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> c(n);
    for (int i=0; i<n; i++) std::cin >> c[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((i+j)%2==0) continue;
            if (c[i][j] == 'B') c[i][j] = 'W';
            else if (c[i][j] == 'W') c[i][j] = 'B';
        }
    }

    MaxFlow<long long> graph(n*n+2);

    const int s = n*n; const int t = n*n+1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            const int node = i*n + j;

            if (c[i][j] == 'W') graph.add_edge(s, node, LONG_MAX/3);
            if (c[i][j] == 'B') graph.add_edge(node, t, LONG_MAX/3);

            if (i>0) {
                graph.add_edge((i-1)*n+j, node, 1);
                graph.add_edge(node, (i-1)*n+j, 1);
            }

            if (j>0) {
                graph.add_edge(i*n+j-1, node, 1);
                graph.add_edge(node, i*n +j-1, 1);
            }
        }
    }

    const auto flow = graph.max_flow(s, t);
    std::cout << 2*n*(n-1) - flow << std::endl;
}