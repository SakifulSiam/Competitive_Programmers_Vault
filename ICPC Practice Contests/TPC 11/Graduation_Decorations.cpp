#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>,
    rb_tree_tag, tree_order_statistics_node_update>;
// os.insert(x); os.erase(x);
// *os.find_by_order(k) -> k-th element, 0-indexed.
// os.order_of_key(x) -> count of elements strictly smaller than x.
// For duplicates, store pair<value, unique_id>.

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const ll inf = LLONG_MAX;
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
    ll n, m, s, r, t, a, b;
    cin>>n>>m>>s>>r>>t>>a>>b;
    ll total = 2*n*m*a;     
    if(total%b){no; return;}
    ll req = total/b;
    ll k = min(r, req/4); 
    req-=4*k;
    k = min(s, req/2); 
    req-=2*k;
    if (req <= t) yes; 
    else no;
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