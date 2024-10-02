#include <bits/stdc++.h>
    
using namespace std;
#define ll long long

int final_value(ll x, ll y, ll rem) {

    while (rem >0 && x != 1) {
        
        ll req = (y - (x%y)) % y;
        if (req > rem) {
            return x + rem;
        }
        x += req;
        rem -= req;

        while(x % y == 0) x /= y;
    }

    if (rem == 0) return x;
    return 1 + rem % (y-1);
}

int main() {
    
    int t; cin >> t;
    while(t-->0) {

        ll x, y, k; cin >> x >> y >> k;

        cout << final_value(x, y, k) << endl;
    }
}