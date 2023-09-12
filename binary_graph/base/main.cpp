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

namespace BG_5 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] = co;
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

namespace BG_6 {
    bool dfs(vector<vector<int> >& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_7 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_8 {
    bool dfs(vector<vector<int>>& g, int pos, int co) {
        if (colors[pos]) {
            return colors[pos] == co;
        }
        colors[pos] = co;
        for (auto& nei : g[pos]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_9 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_10 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_11 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_12 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
                return false;
            }
        }
        return true;
    }
}

namespace BG_13 {
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

namespace BG_14 {
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

namespace BG_15 {
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

namespace BG_16 {
    bool dfs(vector<vector<int>>& g, int idx, int co) {
        if (colors[idx]) {
            return colors[idx] == co;
        }
        colors[idx] = co;
        for (auto& nei : g[idx]) {
            if (!dfs(g, nei, 3 - co)) {
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


using BG_15::dfs;
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
    cout << "8 ans : " << dfs(g, 0, 1) << endl;
}

int main() {
    test();
    return 0;
}
