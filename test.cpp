#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int INF = int(1e9);

int main() {
    
    int t=1; cin >> t;
    while(t-->0) {
        int n, m;
        cin >> n >> m;

        bool ok = false;
        for (int i=0; i<n; i++) {

            int tile[2][2];
            for (int r=0; r<2; r++) 
                for (int c=0; c<2; c++)
                    cin >> tile[r][c];

            if (tile[0][1] == tile[1][0]) ok = true;
        }

        if (ok && (m%2 == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}