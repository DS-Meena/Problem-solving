#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
// #define p pair<int, int>

const int mod = 998244353;
const int N = 1e5;

int solve(int x, int n) {

    // do prime factorization
    multiset<int> primeFactors;

    // how do i track the unique multisets
        
}

int main() {
    
    int t; 
    cin >> t;
    while(t-->0) {
        int k, n;
        cin >> k >> n;

        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

        vector<vector<int>> dp(N, vector<int>(17, 0));
        
        for (int i=0; i<N; i++) dp[i][1] = 1;

        for (int i=0; i<N; i++) {
            for (int j=2; j<17; j++) {

                for (int p : primes) {
                    
                    if (i % p == 0)
                        dp[i][j] += dp[i/p][j-1]; 
                }
            }
        }

        for (int x=1; x<=k; x++) {

            ll ans = 0;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<17; j++) {

                    
                }
            }
        }
        cout << endl;
    }
}