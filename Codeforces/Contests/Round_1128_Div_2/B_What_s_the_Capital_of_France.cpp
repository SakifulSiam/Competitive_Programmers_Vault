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

// WHEN: bitmask DP, subset enumeration, bit tricks.
bool isSet(int mask, int bit) { return (mask >> bit) & 1; }
int setBit(int mask, int bit) { return mask | (1 << bit); }
int clearBit(int mask, int bit) { return mask & ~(1 << bit); }
int toggleBit(int mask, int bit) { return mask ^ (1 << bit); }
bool isPowerOfTwo(ll x) { return x > 0 && (x & (x - 1)) == 0; }
int countBits(unsigned int x) { return __builtin_popcount(x); }

void solve() {
    int n;
    cin>>n;
    vi a(n);
    for(auto &x:a) cin>>x;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(auto x : a){
        mx = max(x,mx);
        mn = min(x,mn);
    }
    if(mx==mn) cout<<mx<<endl;
    else{
        int pos = 32 - __builtin_clz(mx^mn);
        pos = ((1<<(pos))-1)|mx;
        cout<<pos<<endl;
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