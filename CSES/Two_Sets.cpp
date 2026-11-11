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

void solve() {
    ll n;
    cin>>n;
    ll sum= n*(n+1)/2;
    vi a1,a2;
    if(sum & 1){
        no;
        return;
    }
    sum >>= 1;
    for(int i=n; i>0; i--){
        if(sum-i>=0){
            a1.pb(i);
            sum -= i;;
        }
        else{
            a2.pb(i);
        }
    }
    yes;
    cout<<a1.size()<<endl;
    for(auto x : a1) cout<<x<<' '; cout<<endl;
    cout<<a2.size()<<endl;
    for(auto x : a2) cout<<x<<' '; cout<<endl;
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