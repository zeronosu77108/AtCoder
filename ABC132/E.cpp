#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

vector< vector<long> > g;
vector< vector<long> > dist;
long n,m,s,t;
long min_d = LONG_MAX;

void print_dist() {
	cout << "dist : " << endl;
	for (auto i : dist ) {
		for (auto j : i ) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void bfs(queue<pair<long,long>>& q) {
	while( ! q.empty() ) {
		long i = q.front().first;
		long d = q.front().second;
		q.pop();

		//cout << i << " => " ;
		for (auto j : g[i]) {
		//	cout << j << " ";
			if( dist[j][(d+1)%3] == -1 ) {
				dist[j][(d+1)%3] = d+1;
				q.push( make_pair(j,d+1%3));
			}
		}
		//cout << endl;
		//print_dist();
	}
}

int main(void) {
	cin >> n >> m;
	dist = vector< vector<long> > (n+1, vector<long>(3,-1));
	g = vector< vector<long> >(n+1);

	for (long i=0; i<m; i++) {
		long u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	cin >> s >> t;

	queue<pair<long,long>> q;
	q.push(make_pair(s,0));
	bfs(q);
	
//	for (long i=1; i<n; i++) {
//		cout << i << " => ";
//		for (auto j : g[i] ) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}


	cout << (dist[t][0]>0 ? dist[t][0]/3 : -1) << endl;
}

