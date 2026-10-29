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
    vll p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
    bool same(int a, int b){
        a = find(a); b = find(b);
        if (a == b) return true;
        else return false;
    }
};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; edges[i].second--;
    }
    struct Query {
        string type;
        int u, v;
    };
    vector<Query> queries(k);
    for (int i = 0; i < k; i++) {
        cin >> queries[i].type >> queries[i].u >> queries[i].v;
        queries[i].u--; queries[i].v--;
    }
    DSU d(n);
    vector<string> results;
    for (int i = k - 1; i >= 0; i--) {
        if (queries[i].type == "ask") {
            if (d.same(queries[i].u, queries[i].v)) {
                results.push_back("YES");
            } else {
                results.push_back("NO");
            }
        } else {
            d.unite(queries[i].u, queries[i].v);
        }
    }
    reverse(results.begin(), results.end());
    for (const string& res : results) {
        cout << res << '\n';
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