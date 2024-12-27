#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>


int main() {
    
    int t; cin >> t;
    while(t-->0) {

        int n, m, q;
        cin >> n >> m >> q;

        set<p> intervals = {{m, m}};

        while(q-->0) {

            int pos; cin >> pos;

            set<p> updated;

            // update the intervals
            for (auto& it : intervals) {
                
                if (it.first > pos) {
                    updated.insert({it.first-1, it.second});
                } 
                else if (it.second < pos) {
                    updated.insert({it.first, it.second+1});
                }
                else {
                    // tricky part
                    if (it.first != pos) updated.insert({it.first, pos});
                    if (it.second != pos) updated.insert({pos, it.second});
                    updated.insert({1, 1});
                    updated.insert({n, n});
                }
            }

            // merge the intervals (assertion: set is already sorted)
            stack<p> stk;
            for (auto& it : updated) {
                // cout << it.first << " " << it.second << endl;
                if (stk.empty() || stk.top().second < it.first) {
                    stk.push({it.first, it.second});
                } 
                else {
                    p top = stk.top();
                    stk.pop();
                    top.first = min(top.first, it.first);
                    top.second = max(top.second, it.second);
                    stk.push(top);
                }
            }

            // count distinct positions
            int distinct_positions = 0;
            intervals = {};
            while(!stk.empty()) {
                p top = stk.top(); 
                stk.pop();
                intervals.insert(top);

                distinct_positions += top.second - top.first + 1;
                // cout << top.first << " " << top.second << endl;
            }

            cout << distinct_positions << " "; // << endl;
        }
        cout << endl;
    }
}