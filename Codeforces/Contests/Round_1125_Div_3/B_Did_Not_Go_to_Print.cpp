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
    string s;
    cin>>s;
    deque<int> v;
    vector<int> v1;
    for(int i=0; i<n; i++){
        if(s[i]=='1') v.push_front(i+1);
        if(s[i]=='2' && !v.empty()){v.pop_front();v1.pb(i+1);}
    }
    for(auto x : v1) v.pb(x);
    cout<<v.size();
    cout<<endl;
    sort(all(v));
    for(auto x : v) cout<<x<<' ';
    cout<<endl;

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