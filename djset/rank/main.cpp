//
// Created by liguoyang on 2023/3/8.
//
# include <vector>
#include <numeric>
using namespace std;

namespace DJ_RANK_1 {
    vector<int> fa, ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
        iota(begin(fa), end(fa), 0);
    }
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(ry);
        if (rx == ry) {
            return;
        }
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            fa[rx]++;
        }
    }
}

namespace DJ_RANK_2 {
    int n;
    vector<int> fa, ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_RANK_3 {
    int n;
    vector<int> fa, ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        iota(begin(fa), end(fa), 0);
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
        if (rx == ry) {
            return;
        }
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_RANK_4 {
    int n;
    vector<int> fa, ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_RANK_5 {
    int n;
    vector<int> fa, ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        iota(fa.begin(), fa.end(), 0);
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
        if (rx == ry) {
            return;
        }
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = fa[rx];
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}
