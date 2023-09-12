//
// Created by liguoyang on 2023/4/19.
//

#include "../../main.h"

struct DJ {
    int n;
    vector<int> fa;
    DJ(int nn) {
        n = nn;
        fa.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        fa[ry] = rx;
    }
};

namespace LCA_TARJAN_1 {
    int n;
    vector<bool> vis;
    vector<vector<int>> qs;
    vector<vector<int>> g;
    DJ* dj;
    void init(int nn, vector<vector<int>> edges, vector<vector<int>> queries) {
        n = nn;
        vis.resize(n);
        // create graph
        g.resize(n);
        for (auto& e : edges){
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // extract queries
        qs.resize(n);
        for (auto i = 0; i < queries.size(); i++) {
            auto& q = queries[i];
            qs[q[0]].push_back(q[1]);
            if (q[0] != q[1]) {
                qs[q[1]].push_back(q[0]);
            }
        }
        dj = new DJ(n);
    }

    void tarjan(int u, int o) {
        for (auto& v : g[u]) {
            if (v == o) continue;
            tarjan(v, u);
            dj->merge(u, v);
        }
        for (auto& nu : qs[u]) {
            if (nu == u) {
                cout << u << " " << nu << " " << u << endl;
            }
            if (vis[nu]) {
                int rnu = dj->find(nu);
                cout << u << " " << nu << " " << rnu << endl;
            }
        }
        vis[u] = true;
    }
}

namespace LCA_TARJAN_2 {
    int n, m;
    vector<vector<int>> g;
    vector<int> vis;
    vector<vector<pair<int, int>>> qs;
    DJ* dj;
    vector<int> res;
    void init(int nn, vector<vector<int>> edges, vector<vector<int>> queries) {
        n = nn;
        m = queries.size();
        res.resize(m);
        dj = new DJ(n);

        g.resize(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        qs.resize(n);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            qs[x].emplace_back(y, i);
            if (x != y) {
                qs[y].emplace_back(x, i);
            }
        }
        vis.resize(n);
    }
    void tarjan(int u, int o) {
        vis[u] = true;
        for (auto& v : g[u]) {
            if (v == o) continue;
            tarjan(v, u);
            dj->merge(u, v);
        }
        for (auto& [nu, i] : qs[u]) {
            if (vis[nu]) {
                int fnu = dj->find(nu);
                res[i] = fnu;
            }
        }
    }
}

using LCA_TARJAN_2::init;
using LCA_TARJAN_2::tarjan;
using LCA_TARJAN_2::res;
void test() {
    int n = 11;
    vector<vector<int>> edges = {
            {0, 1},
            {0, 2},
            {0, 3},
            {1, 4},
            {4, 5},
            {4, 6},
            {3, 7},
            {3, 8},
            {2, 9},
            {9, 10}
    };
    // ans: 4 0 3 0 0
    vector<vector<int>> queries = {
            {4, 5},
            {5, 7},
            {3, 7},
            {1, 9},
            {8, 10}
    };
    init(n, edges, queries);
    tarjan(0, -1);
    for (auto& e : res) cout << e << " "; cout << "\n";
}

int main() {
    test();
}