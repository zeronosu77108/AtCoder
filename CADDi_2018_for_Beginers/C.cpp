#include <iostream>
#include <unordered_map> 

using namespace std;

std::unordered_map<long long,long long> c;

void decompositPrime(long long n)
{
    long long a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            n /= a;
            c[a] += 1;
        } else {
            a++;
        }
    }
    c[n]++;
}

int main(void) {
    long long n;
    long long p;
    long long ans=1;
    cin >> n;  cin >> p;
    decompositPrime(p);
    
    for (auto itr = c.begin(); itr != c.end(); itr++) {
        // if ( itr->second >= n ) {
        while ( itr->second >= n ) {
            itr->second -= n;
            ans *= itr->first;
        }
    }
    cout << ans << endl;
}
