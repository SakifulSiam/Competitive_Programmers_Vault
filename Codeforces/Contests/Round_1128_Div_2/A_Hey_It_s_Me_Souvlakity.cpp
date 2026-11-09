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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int f,l,c;
    f=l=c=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1')c++;
    }
    for(int i=0; i<n; i++) 
        if(s[i]=='1'){f=i;break;}
    for(int i=0; i<n; i++) 
        if(s[n-1-i]=='1'){l=n-1-i;break;}
    
// cout<<l<<' '<<f<<endl;

    if(c==1)cout<<0<<endl;
    else if(c==2)cout<<1<<endl;
    else{
        cout<<l-f<<endl;
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