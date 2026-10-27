#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>,
    rb_tree_tag, tree_order_statistics_node_update>;
// os.insert(x); os.erase(x);
// *os.find_by_order(k) -> k-th element, 0-indexed.
// os.order_of_key(x) -> count of elements strictly smaller than x.
// For duplicates, store pair<value, unique_id>.

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const ll inf = LLONG_MAX;
const ll N = 1e3 + 9;
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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> g[n+1];
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vi s(n+1);
    for(int i=1; i<=n; i++) cin>>s[i];
    vector<vll> dist(n + 1, vll(1001, inf));
    dist[1][s[1]] = 0;
    using T = tuple<ll,int,int>; // (dist, city, speed)
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 1, s[1]});
    while (!pq.empty()) {
        auto [d, u, cur] = pq.top(); pq.pop();
        if (d != dist[u][cur]) continue;
        for (auto [v, w] : g[u]) {
            ll nd = d + (ll)w * cur;
            int ns = min(cur, s[v]);
            if (nd < dist[v][ns]) {
                dist[v][ns] = nd;
                pq.push({nd, v, ns});
            }
        }
    }
    ll ans = inf;
    for (int j = 1; j <= 1000; j++) ans = min(ans, dist[n][j]);
    cout << ans << endl;
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