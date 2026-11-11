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
    vi a(n);
    list<int> li;
    vector<list<int>::iterator> w(n);
    
    auto next_ = [&](list<int>::iterator it){
        return it == --li.end() ? li.begin():++it;
    };
    auto prev_ = [&](list<int>::iterator it){
        return it == li.begin() ? --li.end():--it;
    };
    auto hole = [&](list<int>::iterator it){
        return a[*it] <= min(a[*prev_(it)], a[*next_(it)]);
    };
    for(int i=0; i<n; i++) {
        cin>>a[i];
        w[i] = li.insert(li.end(), i);
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(hole(w[i])) q.push(i);
    }

    ll ans = 0;
    vector<bool> remove(n, false);

    while(li.size()>1){
        int i=q.front();
        q.pop();
        if(remove[i]) continue;
        remove[i]=1;
        auto it = w[i];
        ans += min(a[*prev_(it)], a[*next_(it)]);
        auto nt = next_(it);
        auto pt = prev_(it);
        li.erase(it);
        if(hole(nt)){
            q.push(*nt);
        }
        if(hole(pt)){
            q.push(*pt);
        }
    }
    cout<<ans<<endl;
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