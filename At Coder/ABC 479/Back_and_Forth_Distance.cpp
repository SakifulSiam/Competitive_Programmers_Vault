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
    int n,q;
    cin>>n>>q;
    vi l(n),r(n);
    l[0]=INT_MAX;
    r[n-1]=INT_MAX;
    vi minl(n);
    vi minr(n);
    for(int i=1; i<n; i++) cin>>l[i];
    for(int i=0; i<n-1; i++) cin>>r[i];
    minl[n-1]=l[n-1];
    minr[0]=r[0];
    for(int i=n-2; i>=0; i--){
        minl[i]=min(minl[i+1],l[i]);
    }
    for(int i=1; i<n; i++){
        minr[i]=min(minr[i-1],r[i]);
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        s--;t--;
        if(s==t) cout<<0<<endl;
        else if(s<t){//right
            if(s==0)
            cout<<r[s]<<endl;
            else
            cout<<min(r[s],l[s]+minr[s-1])<<endl;
        }
        else{//left
            if(s==n-1)
            cout<<l[s]<<endl;
            else
            cout<<min(l[s],r[s]+minl[s+1])<<endl;
        }
    }
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