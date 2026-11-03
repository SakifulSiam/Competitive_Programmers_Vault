#include <bits/stdc++.h>
using namespace std;

struct TopoSort {
    int n;
    vector<vector<int>> adj;
    vector<int> order;
    vector<int> pos;
    TopoSort(int _n) {
        n = _n;
        adj.resize(n + 1);
        pos.resize(n + 1);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool build() {
        vector<bool> vis(n + 1, false);
        order.clear();

        auto dfs = [&](auto& self, int u) -> void {
            vis[u] = true;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    self(self, v);
                }
            }
            order.push_back(u);
        };

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
            }
        }
        reverse(order.begin(), order.end());

        for (int i = 0; i < (int)order.size(); i++) {
            pos[order[i]] = i;
        }

        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                if (pos[u] >= pos[v]) {
                    order.clear(); 
                    return false;  
                }
            }
        }
        return true;
    }
};

void solve() {
    int n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    TopoSort ts(26);
    for (int i = 0; i < n - 1; i++) {
        string w1 = s[i];
        string w2 = s[i + 1];
        int len = min(w1.size(), w2.size());
        bool diff_found = false;
        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a' + 1;
                int v = w2[j] - 'a' + 1;
                ts.add_edge(u, v);
                diff_found = true;
                break; 
            }
        }
        if (!diff_found && w1.size() > w2.size()) {
            cout << "Impossible\n";
            return;
        }
    }
    if (!ts.build()) {
        cout << "Impossible\n"; 
    } else {
        for (int u : ts.order) {
            cout << char((u - 1) + 'a');
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}