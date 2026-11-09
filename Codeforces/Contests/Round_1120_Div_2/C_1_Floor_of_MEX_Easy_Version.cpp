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
    int n; cin >> n;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<pii> badivs;
    for(int i = 1; i <= n; i++) {
        badivs.pb({b[i] * i, (b[i] + 1) * i - 1});
    }
    vector<int> d(n + 1);
    for(auto [l, r] : badivs) {
        d[min(n, l)]++;
        d[min(n, r + 1)]--;
    }
    int csm = 0;
    vector<int> gnums;
    for(int i = 0; i < n; i++) {
        csm += d[i];
        if(csm == 0) {
            gnums.pb(i);
        }
    }
    cout << gnums.size() << endl;
    for(int i : gnums) cout << i << " ";
    cout << endl;
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