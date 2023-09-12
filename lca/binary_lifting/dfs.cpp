//
// Created by liguoyang on 2023/6/19.
//
#include "../../main.h"

// __builtin_ctz() / __buitlin_ctzll()
// 返回元素的二进制表示末尾0的个数
// 比如 __builtin_ctz(8) = 3
// 8 = 1000 , 末尾有3个0

// __buitlin_clz() / __buitlin_clzll()
// 返回元素的二进制表示前导0的个数
// 比如 __builtin_ctz(8) = 28
// 8 = 0000 0000 0000 0000 0000 0000 0000 1000 , 整型(int)为32位,有28个前导0


namespace BL_1 {
    // n : 节点数量
    // m : n的二进制长度
    int n, m;
    vector<int> dep;
    vector<vector<int>> g;
    vector<vector<int>> st;
    // 1. 初始化 + 计算倍增数组
    void init(int nn, vector<vector<int>>& edges) {
        n = nn;
        m = 32 - __builtin_clz(n);

        g.resize(n);
        dep.resize(n);
        st.resize(n, vector<int>(m, -1));

        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }

        function<void(int, int)> dfs = [&](int u, int o) {
            st[u][0] = o;
            for (auto& v : g[u]) {
                if (v != o) {
                    dep[v] += dep[u] + 1;
                    dfs(v, u);
                }
            }
        };
        dfs(0, -1);

        for (int i = 1; i < m; i++) {
            for (int u = 0; u < n; u++) {
                if (st[u][i - 1] != -1) {
                    st[u][i] = st[st[u][i - 1]][i - 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << st[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 2. 根据倍增数组计算lca
    int lca(int x, int y) {
        // 将 y 置于 较深的位置
        if (dep[x] > dep[y]) {
            swap(x, y);
        }

        // 让 x 和 y 位于同一深度
        int d = dep[y] - dep[x];
        for (; d; d &= d - 1) {
            int i = __builtin_ctz(d);
            y = st[y][i];
        }
        if (y == x) {
            return x;
        }

        // 从大到小往上跳
        for (int i = m - 1; i >= 0; i--) {
            if (st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i];
            }
        }

        // 最后返回x的父节点
        return st[x][0];
    }
}

using BL_1::init;
using BL_1::lca;
void test() {
    int n = 8;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {0, 4}, {0, 5}, {2, 6}, {3, 7}};
    init(n, edges);

    // ans: 0 0 1 1 0
    cout << lca(0, 4) << endl;
    cout << lca(1, 4) << endl;
    cout << lca(3, 6) << endl;
    cout << lca(2, 7) << endl;
    cout << lca(4, 6) << endl;
}

int main() {
    test();
}