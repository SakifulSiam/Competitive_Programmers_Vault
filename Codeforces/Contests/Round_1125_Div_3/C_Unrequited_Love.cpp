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
    vi a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    int m = n-4;
    vi v(m);
    for(int i=0; i<m; i++) v[i] = a[i] + a[i+2] - a[i+4];
    vi s = v;
    sort(all(s));
    ll ans = 0;
    int i=0;
    while(i<m) {
        int j = i;
        while(j<m && s[j] == s[i]) j++;
        ll c = j-i;
        ans += c*(c-1)/2;
        i = j;
    }
    for (int i=0; i<m; i++) {
        if(i+2<m && v[i] == v[i+2]) ans--;
        if(i+4<m && v[i] == v[i+4]) ans--;
    }
    cout<<ans<<endl;
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