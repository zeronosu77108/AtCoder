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

vector<int64> Eratosthenes(  int64 N )
{
    N *= 2;
    vector<int64> p;
    vector<bool> is_prime(N+1, true);
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            p.emplace_back( i );
        }
    }
    return p;
}

int main() {
    int64 x;
    cin >> x;
    vector<int64> ans = Eratosthenes(x);
    cout << *lower_bound(ans.begin(), ans.end(), x) << endl;
}