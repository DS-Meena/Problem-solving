#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int INF = int(1e9);

int main() {
    
    int t=1; // cin >> t;
    while(t-->0) {
        int n; cin >> n;

        int totalLength = n-1;   // spaces
        vector<string> text(n);
        for (int i=0; i<n; i++) {
            cin >> text[i];
            totalLength += text[i].length();
        }

        // equal segments starting at i and j
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (text[i] == text[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
            }
        }

        int ans=totalLength;
        for (int i=0; i<n; i++) {
            for (int L=1; L<= n; L++) {
                int j = i+L, cnt=1;

                // count equal segments
                while (j<n) {
                    if (dp[i][j] >= L) {
                        cnt++;
                        j += L;
                    } else 
                        j++;                  
                }

                // calculate segmentLength
                int segLen=L-1;
                for (int k=i; k<i+L; k++) segLen += text[k].length();

                if (cnt>=2) {
                    ans = min(ans, totalLength - cnt*segLen + cnt*L);
                }  
            }
        }

        cout << ans << endl;
    }
}