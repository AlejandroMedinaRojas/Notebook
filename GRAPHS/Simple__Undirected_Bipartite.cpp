int n;
vector<vector<int>> g;
vector<int> mt, vis;
int timer = 0;
bool Khun(int u){
    if (vis[u] == timer) return false;
    vis[u] = timer;
    for (auto &v: g[u]){
        if (mt[v] == -1 || Khun(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}
int MaxMatching(){
    int res = 0;
    fill(mt.begin(), mt.end(), -1);
    for (int i = 0; i < n; ++i){
        ++timer;
        if (Khun(i)) ++res;
    }
    return res;
}

// Khun
// Time complexity O(n * m)
// Space complexity O(n)