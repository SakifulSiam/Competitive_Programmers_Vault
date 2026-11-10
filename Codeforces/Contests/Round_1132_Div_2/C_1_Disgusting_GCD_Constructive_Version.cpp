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

vll is_prime;
// WHEN: many primality/factorization queries for values <= n.
// TIME: O(n log log n) preprocessing.
vll smallestPrimeFactor(int n) {
    vll spf(n + 1);
    for (int i = 0; i <= n; ++i) spf[i] = i;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (spf[i] != i) continue;
        for (ll j = 1LL * i * i; j <= n; j += i)
            if (spf[j] == j) spf[j] = i;
    }
    vll prime;
    for(int i=2; i<=n; i++){
        if(spf[i]==i) prime.pb(i);
    }
    return prime;
}
void solve() {
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0; i<n; i++){
        cin>>a[i]; 
    }
    for(int i=0; i<n; i++){
        ll ok = lower_bound(all(is_prime),a[i])-is_prime.begin();
        cout<<is_prime[ok]<<' ';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    is_prime = smallestPrimeFactor(N-10);
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}