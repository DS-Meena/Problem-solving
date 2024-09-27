#include <bits/stdc++.h>
    
using namespace std;
#define ll long long
#define p pair<int, ll>

void dijkstra(int source, vector<vector<ll>> &d, vector<vector<p>> &graph, vector<bool> &hs) {

    // comparator for set
    auto cmp = [&](auto &a, auto &b) {
        return make_pair(d[a.first][a.second], a) < 
                make_pair(d[b.first][b.second], b);
    };

    set<pair<int, int>, decltype(cmp)> mnHeap(cmp);

    d[source][0] = 0;
    mnHeap.insert({source, 0});

    while(!mnHeap.empty()) {

        auto [u, withHorse] = *mnHeap.begin();
        mnHeap.erase(mnHeap.begin());

        // do we have a horse
        bool horse = (withHorse || hs[u]);

        for (auto &[v, w] : graph[u]) {

            ll dist = horse ? w/2 : w;
            if (d[v][horse] > d[u][withHorse] + dist) {
                
                mnHeap.erase({v, horse});
                d[v][horse] = d[u][withHorse] + dist;

                mnHeap.insert({v, horse});
            }
        }
    }
}

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        
        int n, m, h; cin >> n >> m >> h;

        vector<bool> hs(n);
        vector<vector<p>> graph(n);

        for (int i=0; i<h; i++) {
            int x; cin >> x;
            hs[--x] = 1;
        }

        for (int i=0; i<m; i++) {
            int u, v, w; cin >> u >> v >> w;
            
            u--; v--;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<vector<ll>> d1(n, vector<ll>(2, 1e18));
        vector<vector<ll>> d2(n, vector<ll>(2, 1e18));

        dijkstra(0, d1, graph, hs);
        dijkstra(n-1, d2, graph, hs);

        ll best = 1e18;
        // lambda function
        auto get = [&](int a) {return max(min(d1[a][0], d1[a][1]), min(d2[a][0], d2[a][1]));};

        for (int i=0; i<n; i++) {
            best = min(best, get(i));
        }

        cout << (best == 1e18 ? -1 : best) << endl;
    }
}