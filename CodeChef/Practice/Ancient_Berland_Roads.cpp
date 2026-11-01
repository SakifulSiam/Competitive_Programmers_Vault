#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const ll inf = 1e18;
const ll N = 5e5 + 9;
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

vll p(N), sz(N);
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int size(int x) { return sz[find(x)]; }

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vll curP(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> curP[i];
        p[i] = i; 
    }
    vector<pii> road(m + 1);
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        road[i] = {x, y};    
    }
    using T = tuple<char, int, ll>;
    vector<T> query(q);
    vector<bool> mp(m + 1, false);
    for(int i = 0; i < q; i++){
        char c;
        cin >> c; 
        if(c == 'D'){
            int k;
            cin >> k;
            query[i] = {c, k, 0};
            mp[k] = true;
        }
        else{
            int k; ll x;
            cin >> k >> x;
            query[i] = {c, k, curP[k]};
            curP[k] = x; 
        }
    }
    //------------------------------------------------//
    multiset<ll> ms;
    for(int i = 1; i <= n; i++){
        sz[i] = curP[i];
        ms.insert(sz[i]);
    }
    auto unite = [&](int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        ms.erase(ms.find(sz[a]));
        ms.erase(ms.find(sz[b]));
        p[b] = a; 
        sz[a] += sz[b];
        ms.insert(sz[a]);
        return true;
    };
    for(int i = 1; i <= m; i++){
        if(!mp[i]){
            unite(road[i].ff, road[i].ss);
        }
    }
    vll ans;
    for(int i = q - 1; i >= 0; i--){
        ans.pb(*ms.rbegin()); 
        auto[c, a, b] = query[i];
        if(c == 'D') {
            unite(road[a].ff, road[a].ss);
        } 
        else {
            int root = find(a);
            ms.erase(ms.find(sz[root]));
            sz[root] += (b - curP[a]); 
            curP[a] = b;               
            ms.insert(sz[root]);
        }
    }
    reverse(all(ans));
    for(auto x : ans){
        cout << x << endl;
    }
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