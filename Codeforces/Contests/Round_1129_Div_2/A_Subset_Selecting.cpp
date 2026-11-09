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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(all(a));
    vi freq(a[n-1]+2,0);
    for(int i=0; i<n; i++) freq[a[i]]++;
    for(int i=1; i<n; i++) if(a[i]!=a[i-1]) freq[a[i]]+=freq[a[i-1]];
    int sum=k;
    for(int i=0; i<=a[n-1]+1; i++){
        // cout<<freq[i]<<' '<<sum<<endl;
        if(freq[i]<sum){
            cout<<i<<endl;
            return;
        }
        sum+=k;
    }
    // set<int> ans;
    // for(int i=0; i<n; i+=k){
    //     if()
    // }
    // int i=0;
    // for(auto st : ans){
    //     if(st!=i){
    //         cout<<i<<endl;
    //         return;
    //     }
    //     i++;
    // }
    // cout<<i<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        // cout<<"tc "<<t<<endl;
        solve();
    }

    return 0;
}