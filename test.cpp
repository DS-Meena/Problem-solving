#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int INF = int(1e9);

map<ll, int> dp[20][20];

ll grid[20][20];
ll half, ans, m, n, k;

void recurseFront(int x, int y, int val, int cnt) {
    val ^= grid[x][y];

    if (cnt == half) {
        ++dp[x][y][val];
        return;
    }
    
    if (x+1 < m)
        recurseFront(x+1, y, val, cnt+1);
    if (y+1 < n)
        recurseFront(x, y+1, val, cnt+1);
}

void recurseBack(int x, int y, int val, int cnt) {

    if (cnt == n + m - 2 - half) {
        if (dp[x][y].count(k^val) > 0) {
            ans += dp[x][y][k^val];
            return;
        }
    }

    val ^= grid[x][y];

    if (x > 0)
        recurseBack(x-1, y, val, cnt+1);
    if (y > 0)
        recurseBack(x, y-1, val, cnt+1);
}

int main() {
    
    int t=1; // cin >> t;
    while(t-->0) {
        cin >> m >> n >> k;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                cin >> grid[i][j];
        }

        half = (n + m - 2) / 2;

        recurseFront(0, 0, 0, 0);
        recurseBack(m-1, n-1, 0, 0);

        cout << ans << endl;
    }
}