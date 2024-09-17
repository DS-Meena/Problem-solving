#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        int n, m, q; cin >> n >> m >> q;

        vector<int> positions(m);        
        for (int i=0; i<m; i++) 
            cin >> positions[i];
        sort(positions.begin(), positions.end());

        while(q-->0) {
            int pos; cin >> pos;

            // left corner
            if (pos < positions[0]) {
                cout << positions[0]-1 << endl;
                continue;
            }

            // right corner
            if (pos > positions[m-1]) {
                cout << n - positions[m-1] << endl;
                continue;
            }

            // in between
            int k = lower_bound(positions.begin(), positions.end(), pos) - positions.begin();

            cout << (positions[k] - positions[k-1]) /2 << endl;
        }
        
    }
}