#include "../../sum.h"

// 树上倍增
// 1. 快速计算树上第k个祖先

// 方法2
namespace BL_1 {
    constexpr static int Log = 16;
    int n;
    vector<vector<int>> f;
    vector<vector<int>> g;
    vector<int> dep;
    void init(int nn, vector<vector<int>>& edges) {
        n = nn;
        dep.resize(n);
        g = vector<vector<int>>(n);
        f = vector<vector<int>>(n, vector<int>(Log, -1));
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        function<void(int, int)> dfs = [&](int u, int o) {
            f[u][0] = o;
            dep[u] = 0;
            if (f[u][0] != -1) {
                dep[u] = dep[f[u][0]] + 1;
            }
            for (int i = 1; i < Log; i++) {
                if (f[u][i - 1] != -1) {
                    f[u][i] = f[f[u][i - 1]][i - 1];
                }
            }
            for (auto& v : g[u]) {
                if (v == o) {
                    continue;
                }
                dfs(v, u);
            }
        };
        dfs(0, -1);
    }
    int lca(int x, int y) {
        if (dep[x] > dep[y]) {
            swap(x, y);
        }
        int t = dep[y] - dep[x];
        for (int i = 0; t; i++, t >>= 1) {
            if (t & 1) {
                y = f[y][i];
            }
        }
        if (y == x) {
            return y;
        }
        for (int i = 15; i >= 0 && x != y; i--) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }

        return f[y][0];
    }
}



//-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//1 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//1 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//2 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//3 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
using namespace BL_1;
void test() {
    int n = 8;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {0, 4}, {0, 5}, {2, 6}, {3, 7}};
    init(n, edges);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Log; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << dep[i] << " ";
    }
    cout << endl;

    cout << f[6][1] << " " << f[7][1] << endl;


    // 1
    cout << lca(6, 7) << endl;
    // 1
    cout << lca(1, 7) << endl;
    // 0
    cout << lca(2, 4) << endl;
    // 1
    cout << lca(2, 7) << endl;

}

int main() {
    test();
}