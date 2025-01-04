#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int INF = int(1e9);

int main() {
    
    int t=1; // cin >> t;
    while(t-->0) {
        int n; cin >> n;
        vector<string> text(n);
        for (int i=0; i<n; i++)
            cin >> text[i];

        for (int start=0; start<n; start++) {
            string cur="";

            for (int i=start; i<n; i++) {
                cur += text[i];

                // search in next substring
                
            }

        }    
    }
}