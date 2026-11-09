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
    vector<vi> mat(n+1,vi(n+1,0));
    if(k<n||k>=n*2){
        cout<<-1<<endl;
        return;
    }
    else{
        int cnt = k-n+1;
        for(int i=1; i<=cnt; i++){
            mat[i][1]=i;
        }
        int rest = cnt+1;
        for(int i=rest; i<=n; i++){
            mat[i][i]=i;
        }
        int val = n+1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!mat[i][j]){
                    mat[i][j]=val;
                    val++;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
                cout<<mat[i][j]<<' ';
            }
            cout<<endl;
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