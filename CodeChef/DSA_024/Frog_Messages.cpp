#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

#define endl '\n'
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

void solve() {
    int n, p;
    ll k;
    cin >> n >> k >> p;
    vector<pll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(all(a));
    vi comp(n + 1);
    int id = 1;
    comp[a[0].ss] = id;
    for (int i = 1; i < n; i++) {
        if (a[i].ff - a[i - 1].ff > k) {
            id++;
        }
        comp[a[i].ss] = id;
    }
    while (p--) {
        int u, v;
        cin >> u >> v;
        if (comp[u] == comp[v]) yes;
        else no;
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