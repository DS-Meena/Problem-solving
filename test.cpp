#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, int>

const int mod = int(1e9) + 7;

void input(vector<vector<int>>& adj, int m) {
    for (int i=0; i<m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

int find(int i, vector<int>& par) {

    while(par[i] != i) {
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}

void merge(int a, int b, vector<int>& par, vector<int>& rank) {
    a = find(a, par);
    b = find(b, par);

    if (a == b) return;

    if (rank[a] > rank[b]) {
        rank[a] += rank[b];
        par[b] = a;
    } else {
        rank[b] += rank[a];
        par[a] = b;
    }
}

int main() {
    
    int t; 
    cin >> t;
    while(t-->0) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;

        vector<vector<int>> adj1(n+1), adj2(n+1);
        input(adj1, m1);
        input(adj2, m2);

        vector<int> par1(n+1), rank1(n+1, 1), par2(n+1), rank2(n+1, 1);
        for (int i=1; i<=n; i++)
            par1[i] = par2[i] = i;

        for (int i=1; i<=n; i++)
            for (int v : adj2[i]) merge(i, v, par2, rank2);
        

        int ans = 0;
        // remove operations
        for (int i=1; i<=n; i++) {
            
            vector<int> safe;
            for (int v : adj1[i]) {

                // belong to different components
                if (find(v, par2) != find(i, par2))
                    ans++;
                else 
                    safe.push_back(v);
            }

            adj1[i] = safe;
        }

        // now create dsu of F
        for (int i=1; i<=n; i++)
            for (int v : adj1[i]) merge(i, v, par1, rank1);

        // addition operations
        for (int i=1; i<=n; i++) {

            for (int v : adj2[i]) {

                // belong to different components
                if (find(v, par1) != find(i, par1)) {
                    ans++;
                    merge(i, v, par1, rank1);
                }
            }
        }

        cout << ans << endl;
    }
}