#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

ll maxEarningsGivenPrice(vector<int>& ar, vector<int>& br, int price, int k) {
    int n = ar.size();

    // for every price - i just need (number of trees bought, number of negative reviews)

    ll trees_sold = lower_bound(br.begin(), br.end(), price) - br.begin();
    ll pos_reviews = lower_bound(ar.begin(), ar.end(), price) - ar.begin();
    trees_sold = n - trees_sold;
    pos_reviews = n - pos_reviews;

    if (trees_sold - pos_reviews <= k)
        return price * trees_sold;
    return 0;
}

int main() {
    
    int t; cin >> t;
    while(t-->0) {

        int n, k; cin >> n >> k;
        vector<int> ar(n), br(n);
        for (int i=0; i<n; i++) cin >> ar[i];
        for (int i=0; i<n; i++) cin >> br[i];

        sort(ar.begin(), ar.end());
        sort(br.begin(), br.end());

        // I have 2n prices to check
        ll mx = 0;
        for (int i=0; i<n; i++) {
            mx = max(mx, maxEarningsGivenPrice(ar, br, ar[i], k));
        }
        for (int i=0; i<n; i++) {
            mx = max(mx, maxEarningsGivenPrice(ar, br, br[i], k));
        }

        cout << mx << endl;
    }
}