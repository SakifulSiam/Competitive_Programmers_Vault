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
    int n;
    cin>>n;
    int x = 1;
    while(2*x<=n) x*=2;
    vi p;
    for(int i = 0; i < x; i++) p.pb(i);
    for(int i = x - 1; i >= 0; i--) p.pb(i);
    for(int i = x; i < 2 * x; i++) p.pb(i);
    for(int i = 2 * x - 1; i >= x; i--) p.pb(i);
    cout<<sz(p)-1<<endl;
    for(int i=1; i<sz(p); i++) {
        cout<<(p[i]^p[i-1])<<" ";
    }
    cout<<endl;
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