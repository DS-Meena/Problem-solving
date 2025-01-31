#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int mod = 998244353;
const int N = 1e5;

int main() {
    
    int t; 
    cin >> t;
    while(t-->0) {
        
        int n;
        cin >> n;

        cout << "1 1 ";
        for (int i=3; i<n; i++)
            cout << i << " ";
        cout << "1\n";
    }
}