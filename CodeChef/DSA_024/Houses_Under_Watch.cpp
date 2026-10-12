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
    int m,x,y;
    cin>>m>>x>>y;
    vi a(m);
    for(int i=0; i<m; i++) cin>>a[i];
    vi v(101,1);
    for(int i=0; i<m; i++){
        for(int j = a[i]-x*y; j<=a[i]+x*y; j++){
            if(j<=101&&j>=1)v[j]=0;
        }
    }
    cout<<accumulate(all(v),0)-1<<endl;
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