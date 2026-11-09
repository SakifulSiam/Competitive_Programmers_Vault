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
#define m cout << "Moggity\n"
#define l cout << "Larpity\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin>>n;
    vi a(n);
    int ec,oc;
    ec=oc=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]&1) oc++;
        else ec++;
    }
    // cout<<ec<<" "<<oc<<endl;
    if(n==1){m;return;}
    if(ec==1 && oc==1){l;return;}
    if(oc==0){m;return;}
    if(ec){
        m;

    }
    else{
        if(oc&1) l;
        else m;
    }
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