#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

long long gcd(long long a,long long b){
	if (a%b==0){
		return(b);
    }
	else{
		return(gcd(b,a%b));
    }
}


int main(void) {
    long long a,b,c,d;
    // long long count=0;
    cin >> a >> b >>  c >> d;
    long long ans1,ans2;
    long long GCD = gcd(c,d);
    a--;
    ans1 = a/c + a/d - a/((c*d)/GCD);
    ans2 = b/c + b/d - b/((c*d)/GCD);
    // cout <<  a/c << " " << a/d << " " <<  a/((c*d)/GCD) << endl;
    // cout <<  b/c << " " << b/d << " " <<  b/((c*d)/GCD) << endl;
    
    // cout << ans1 << " " << ans2 << endl;
    cout << (b-a) - (ans2 - ans1) << endl;
    // cout << (long long)ceil(range - (ceil(range/c) + ceil(range/d) - ceil(range/(c*d))))  << endl;
}
