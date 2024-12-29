#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int INF = int(1e9);

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        int n, x, y;
        cin >> n >> x >> y;
        x--; y--;

        int dist = y-x;

        vector<int> a(n);
        for (int i=0; i<n; i++) a[(x+i) % n] = i%2;

       if (n%2 || dist%2 == 0)
            a[x] = 2;

        for (int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
    }
}