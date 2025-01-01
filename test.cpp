#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int INF = int(1e9);

int main() {
    
    int t=1; // cin >> t;
    while(t-->0) {
        int n, k; 
        cin >> n >> k;
        
        vector<int> ar(n);
        for (int i=0; i<n; i++) cin >> ar[i];

        double global_mx=0;
        
        // all window sizes
        for (double size=k; size<= n; size++) {

            // first window
            double sum = 0;
            for (int i=0; i<size; i++)
                sum += ar[i];
            
            double local_mx= sum/size;

            // other windows
            for (int i=size; i<n; i++) {
                sum -= ar[i-size];
                sum += ar[i];

                double curr = sum/size;
                if (curr > local_mx) local_mx = curr;
            }

            if (local_mx > global_mx)
                global_mx = local_mx;
        }

        cout << std::fixed << std::setprecision(7) << global_mx << endl;
    }
}