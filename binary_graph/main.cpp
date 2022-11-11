#include <iostream>
#include <vector>
using namespace std;



vector<vector<int>> g;
vector<int> colors;

namespace BG_1 {
    vector<int> colors;
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_2 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_3 {
    bool dfs(vector<vector<int> >& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto u : g[idx]) {
            if (!dfs(g, u, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_4 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto u : g[idx]) {
            if (!dfs(g, u, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

void init(int n, vector<vector<int>> edges) {
    colors.resize(n);
    g.resize(n);
    for (auto e : edges) {
        int x = e[0], y = e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
}


using BG_2::dfs;
void test() {
    int n = 4;
    // ans : false
    vector<vector<int>> edges = {
            {0, 1},
            {1, 2},
            {0, 2},
            {2, 3}
    };
    init(n, edges);
    cout << "ans : " << dfs(g, 0, 1) << endl;
}

int main() {
    test();
    return 0;
}
