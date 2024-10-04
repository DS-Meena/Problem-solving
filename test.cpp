#include <bits/stdc++.h>
    
using namespace std;
#define ll long long

int main() {
    
    int t; cin >> t;
    while(t-->0) {

        ll a, b, l; 
        cin >> a >> b >> l;

        set<ll> myset;

        for (ll x=0; x<30; x++) {
            for (ll y=0; y<30 && pow(a, x) * pow(b, y) <= l; y++) {

                ll prod = pow(a, x) * pow(b, y);
                if (l % prod == 0) {
                    myset.insert(l/prod);
                }
            }
        }

        cout << myset.size() << endl;
    }
}