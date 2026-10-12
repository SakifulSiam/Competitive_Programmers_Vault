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
    ll n,k;
    cin>>n>>k;

    vll sum(n), extra(n);
    vector<bool> zero(n,0);
    ll cap = LLONG_MAX;;
    ll lo = LLONG_MAX;
    for(int i=0; i<n; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        sum[i]=a+b+c;
        lo = min(lo,sum[i]);
        if(a==b && b==c) zero[i]=1;
        if(a<=b && b<=c) extra[i]=min(b-a,c-b)+1;
        if(zero[i]) cap = min(cap,sum[i]);
    }
    ll hi = min(cap,lo+k)+1;
    auto ok = [&](ll m) {
    ll need = 0;

    for (int i = 0; i < n; i++) {
        if (sum[i] >= m) continue;
        if (zero[i]) return false;
        need += m - sum[i] + 2 * extra[i];
        if (need > k) return false;
    }
    return true;
    };
    while(hi-lo>1){
        ll mid = lo + (hi-lo)/2;
        ll tot = 0;
        if(ok(mid)) lo = mid;
        else hi = mid;
    }
    cout<<lo<<endl;
    
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