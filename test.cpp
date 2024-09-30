#include <bits/stdc++.h>
    
using namespace std;
#define ll long long

int min_operations(int n, int k) {
    if (k == 1) return n;

    int ans = 0;
    while(n) {
        ans += n % k;
        n /= k;
    }

    return ans;
}

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        
        int n, k; cin >> n >> k;

        cout << min_operations(n, k) << endl;
    }
}