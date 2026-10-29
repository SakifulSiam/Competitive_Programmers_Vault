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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,ll>> g[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
    }
    using T = tuple<ll,int,int>;
    vector<vll> dist(n+1, vll(2,inf));
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[1][0] = 0; pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if (d > dist[u][used]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            
            if(!used && dist[v][1] > d + w/2){
                dist[v][1] = d + w/2;   
                pq.push({dist[v][1], v, 1});
            }
        }
    }
    cout<<min(dist[n][0], dist[n][1])<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    //cin >> tc;
    for(int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}