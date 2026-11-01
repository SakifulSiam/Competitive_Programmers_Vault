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

struct DSU {
    ll cnt;
    vll p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1), cnt(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        cnt--;
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return sz[find(x)]; }
    int count() { return cnt; }
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pii> in(m);
    for(auto &x : in) cin>>x.ff>>x.ss;
    int q;
    cin>>q;
    vi qur(q);
    for(auto &y : qur) cin>>y;
    map<int,bool> mp;
    for(auto y : qur){
        mp[y]=1;
    }
    DSU d(n);
    for(int i=1; i<=m; i++){
        if(mp[i])continue;
        d.unite(in[i-1].ff,in[i-1].ss);
    }
    vi ans(q);
    for(int i=q-1; i>=0; i--){
        ans[i]=d.count();
        d.unite(in[qur[i]-1].ff,in[qur[i]-1].ss);
    }
    for(auto print:ans)cout<<print<<' ';
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