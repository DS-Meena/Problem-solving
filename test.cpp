#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int mod = int(1e9) + 7;

int add(int x, int y) {
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % mod;
}

const int N = 200043;
const int K = 4;
int dp[N][K][K];
int pow3[N];

int main() {
    
    int t=1; // cin >> t;
    while(t-->0) {
        int n; 
        cin >> n;
        
        string s;
        cin >> s;

        // count of ? marks
        int cnt=0;
        for (auto c : s) 
            if (c == '?') cnt++;


        // power of 3's
        pow3[0] = 1;
        for (int i=1; i<N; i++)
            pow3[i] = mul(pow3[i-1], 3);

        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for (int i=0; i<n; i++) {
            for (int j=0; j<=3; j++) {

                for (int k=0; k<=3; k++) {

                    if (!dp[i][j][k]) continue;

                    // not matches
                    dp[i+1][j][k] = add(dp[i+1][j][k], dp[i][j][k]);

                    // matches
                    if (j < 3 && (s[i] == '?' || s[i]-'a' == j)) {
                        int nk = (s[i] == '?') ? k + 1 : k;

                        dp[i+1][j+1][nk] = add(dp[i+1][j+1][nk], dp[i][j][k]);
                    }
                }
            }
        }

        int ans = 0;
        for (int i=0; i<=3; i++)
            if (cnt >= i)
                ans = add(ans, mul(dp[n][3][i], pow3[cnt - i]));

        cout << ans << endl;
    }
}