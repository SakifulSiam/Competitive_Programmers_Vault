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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,ll>> g[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
    }
    vll ans;
    vi cnt(n+1,0);
    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        cnt[u]++;
        if(cnt[u]>k) continue;
        if(u==n)ans.pb(d);
        for (auto [v, w] : g[u]) {
            pq.push({d + w, v});
        }
    }
    for(auto x : ans){cout<<x<<' ';}
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