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
    // cout<<1;
    ll n,m;
    cin>>n>>m;
    vll a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vll pref(n+1);
    for(int i=1; i<=n; i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    int j=1;
    int mx = 0;
    for(int i=0; i<n; i++){
        if(j<i)j=i;
        while(pref[j]-pref[i]<=m){
            mx = max(mx,j-i);
            j++;
            if(j>n){cout<<mx<<endl;return;};
        }
    }
    cout<<mx<<endl;
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