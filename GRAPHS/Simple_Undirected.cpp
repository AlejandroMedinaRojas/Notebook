int n;
vector<vector<int>> g;
vector<int> dis, pars;
int ShortestCycle(){
    int res = 1e9;
    for (int i = 0; i < n; ++i){
        fill(dis.begin(), dis.end(), -1);
        fill(pars.begin(), pars.end(), -1);
        
        queue<int> qu;
        qu.push(i);
        dis[i] = 0;
        
        while (!qu.empty()){
            int u = qu.front(); qu.pop();
            for (int &v: g[u]){
                if (dis[v] == -1){
                    qu.push(v);
                    dis[v] = dis[u] + 1;
                    pars[v] = u;
                }
                else if (pars[v] != u && pars[u] != v) res = min(res, dis[u] + dis[v] + 1);
            }
        }
    }
    if (res == 1e9) return 0;
    return res;
}

// Time complexity O(n * (n + m))
// Space complexity O(n)