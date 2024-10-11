#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

int main() {
    
    int t; cin >> t;
    while(t-->0) {

        int n, k; 
        cin >> n >> k;

        vector<p> monsters(n);
        for (int i=0; i<n; i++) cin >> monsters[i].second;
        for (int i=0; i<n; i++) cin >> monsters[i].first;

        sort(monsters.begin(), monsters.end(), [](p a, p b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        });

        ll total_damage=0, curr_attack = k;

        for (int i=0; i<n; i++) {

            // effect of last attack
            if (i > 0)
                curr_attack -= monsters[i].first;

            // kill the monster
            while(monsters[i].second > total_damage && curr_attack > 0) {
                total_damage += curr_attack;

                if (monsters[i].second > 0)
                    curr_attack -= monsters[i].first;
            }

            if (curr_attack <= 0)
                break;
        }

        if (monsters[n-1].second > total_damage) cout <<"NO\n";
        else cout << "YES\n";
    }
}