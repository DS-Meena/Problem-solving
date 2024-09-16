#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        int n, m, q; cin >> n >> m >> q;

        vector<int> positions(n+1, 0);
        
        // input teachers position
        for (int i=0; i<m; i++) {
            int pos; cin >> pos;
            positions[pos] = 1;
        }

        // calculate leftMax and rightMin positions of teachers
        vector<int> leftMax(n+1), rightMin(n+1);
        int left = 0;
        for (int i=1; i<=n; i++) {
            if (positions[i] == 1) left = i;
            leftMax[i] = left;
        }
        int right = n+1;
        for (int i=n; i>0; i--) {
            if (positions[i] == 1) right = i;
            rightMin[i] = right;
        }

        while(q-- > 0) {

            // input david's position
            int pos; cin >> pos;
            int i = leftMax[pos], j = rightMin[pos];

            // if trapped in a corner
            if (i == 0) {
                cout << j-1;
            } else if(j == n+1) {
                cout << n - i;
            } else {
                cout << (j-i)/2;
            }

            cout << endl;
        }
    }
}