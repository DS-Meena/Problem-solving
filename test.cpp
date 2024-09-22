#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        
        int n, d, k; cin >> n >> d >> k;
        vector<int> l(k), r(k);
        for (int i=0; i<k; i++) {
            cin >> l[i] >> r[i];
        }
        
        // apply prefix sum 
        vector<int> psum(n+2, 0);
        for (int i=0; i<k; i++) {
            psum[l[i]]++;
            psum[r[i]+1]--;
        }   

        for (int i=2; i<=n+1; i++) {
            psum[i] += psum[i-1];
        }

        // sliding window - find window with max maximum value
        
    }
}