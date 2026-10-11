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
    int n, k;
    cin >> n >> k;
    vi cnt(n + 2, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    bool ok = false;
    for(int v = 0; v <= n + 1; v++) {
        if(cnt[v] < 2 * k) {
            if(cnt[v] == 2 * k - 1) ok = true;
            break;
        }
    }
    if(ok) yes;
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