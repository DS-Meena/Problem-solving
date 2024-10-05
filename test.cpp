#include <bits/stdc++.h>
    
using namespace std;
#define ll long long

int main() {
    
    int t; cin >> t;
    while(t-->0) {

        int n; cin >> n;

        vector<vector<int>> seq(n, vector<int>(n-1));

        for (int i=0; i<n; i++) 
            for (int j=0; j<n-1; j++) 
                cin >> seq[i][j];

        unordered_map<int, int> freq;
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n; j++) {
                freq[seq[j][i]] += n-i;
            }
        }

        vector<pair<int, int>> ans(n+1);
        for (int i=1; i<=n; i++)
            ans[i] = {freq[i], i};
        sort(ans.begin(), ans.end());

        for (int i=n; i>=1; i--)
            cout << ans[i].second << " ";
        cout << endl;
    }
}