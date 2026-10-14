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
    vll a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    ll s0 = a[0],s1=a[0],ans=a[0];
    for (int i=1;i<n;i++) {
        ans=max(ans, max(a[i]+s1,a[i]-s0));
        s0=min(a[i],min(a[i]+s0,a[i]+2*s0));
        s1=max(a[i],max(a[i]+s1,a[i]+2*s1));
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