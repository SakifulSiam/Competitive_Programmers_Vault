#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const ll inf = 1e18;
const ll N = 3e5 + 9;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

#define endl '\n'
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
struct TopoSort {
    int n;
    vector<vector<int>> adj;
    vector<int> order;
    vector<int> pos;
    TopoSort(int _n) {
        n = _n;
        adj.resize(n + 1);
        pos.resize(n + 1);
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
    bool build() {
        vector<bool> vis(n + 1, false);
        order.clear();
        auto dfs = [&](auto& self, int u) -> void {
            vis[u] = true;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    self(self, v);
                }
            }
            order.push_back(u);
        };
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
            }
        }
        reverse(order.begin(), order.end());
        for (int i = 0; i < (int)order.size(); i++) {
            pos[order[i]] = i;
        }
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                if (pos[u] >= pos[v]) {
                    order.clear(); 
                    return false;
                }
            }
        }
        return true;
    }
};
void solve() {
    int n;
    cin>>n;
    TopoSort tp(n);
    for(int i=1; i<n; i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x<=y)tp.add_edge(u,v);
        else tp.add_edge(v,u);
    }
    tp.build();
    vi ans(n+1);
    for(int i=0; i<n; i++){
        ans[tp.order[i]]=i+1;
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}