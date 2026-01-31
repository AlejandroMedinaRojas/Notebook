vector<vector<int>> g;
vector<bool> vis, curs;
bool IsCycle(int u){
    if (curs[u]) return true;
    if (vis[u]) return false;
    vis[u] = curs[u] = true;
    for (int &v: g[u]){
        if (IsCycle(v)) return true;
    }
    curs[u] = false;
    return false;
}

// IsCycle
// Time complexity O(n + m)
// Space complexity O(n)