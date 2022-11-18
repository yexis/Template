#include <iostream>
#include <vector>
using namespace std;

namespace X {

    vector<int> f, g, h;
    void dfs (vector<vector<int> >& ga, int idx, int fa) {
        if (ga[idx].size() == 1 && ga[idx][0] == fa) {
            h[idx] = 1;
            return;
        }
        h[idx] = 1;
        for (auto nei : ga[idx]) {
            if (nei == fa) {
                continue;
            }
            dfs(ga, nei, idx);
            f[idx] += f[nei] + h[nei];
            h[idx] += h[nei];
        }
    }

    void dfs2(vector<vector<int> >& ga, int idx, int fa) {
        g[idx] = f[idx] + g[fa] - (f[idx] + h[idx]) + ga.size() - h[idx];
        for (auto nei : ga[idx]) {
            if (nei == fa) {
                continue;
            }
            dfs2(ga, nei, idx);
        }
    }

    vector<int> sumDistanceInTree(int n, vector<vector<int> >& edges) {
        f.resize(n);
        g.resize(n);
        h.resize(n);
        vector<vector<int> > ga(n);
        for (auto e : edges) {
            int x = e[0], y = e[1];
            ga[x].push_back(y);
            ga[y].push_back(x);
        }
        dfs(ga, 0, -1);

        g[0] = f[0];
        for (auto nei : ga[0]) {
            dfs2(ga, nei, 0);
        }
        return g;
    }

    void test() {
        int n = 6;
        vector<vector<int> > edges = {
                {0,1},
                {0,2},
                {2,3},
                {2,4},
                {2,5}
        };
        vector<vector<int> > edges2 = {
        };
        vector<vector<int> > edges3 = {
                {1,0}
        };
        auto res = sumDistanceInTree(2, edges3);
        for (auto e : res) {

        }
    }
}

int main() {
    X::test();
    return 0;
}
