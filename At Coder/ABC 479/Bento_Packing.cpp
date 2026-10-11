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
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

void solve() {
    int n,w;
    cin>>n>>w;
    vector<pii> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].ff>>v[i].ss;
    }
    ll mx = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        ll weight = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += v[i].ff;
                weight += v[i].ss;
            }
        }
        if(weight<=w)mx = max(mx,sum);
    }
    cout<<mx<<endl;
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