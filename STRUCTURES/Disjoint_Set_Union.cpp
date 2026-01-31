template<typename T>
struct DSU {

    vector<T> dsu;
    T n, numcomp;

    DSU(T n): n(n), numcomp(n), dsu(n, -1) {}

    T Find(T v){
        return dsu[v] < 0 ? v : dsu[v] = Find(dsu[v]);
    }

    void Union(T u, T v){
        T u = Find(u), v = Find(v);
        if (u != v){
            --numcomp;
            if (pars[u] > pars[v]) swap(u, v);
            pars[u] += pars[v];
            pars[v] = u;
        }
    }

    T CompSize(T u){
        return -dsu[Find(u)];
    }
};

// DSU
// Time complexity O(1)
// Space complexity O(n)