#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct DJ {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
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
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
};

namespace DJ {
    class DJset {
    public:
        int n;
        vector<int> fa;
        vector<int> rank;

        DJset(int n) {
            this-> n = n;
            fa.resize(n);
            rank.resize(n);
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

            // rx > ry
            if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }
            fa[ry] = rx;
            if (rank[rx] == rank[ry]) {
                rank[rx] += 1;
            }
        }
    };
}

namespace DJSet2 {
    vector<int> fa;
    vector<int> rank;
    int n;

    void init(int nn) {
        n = nn;
        fa.resize(n);
        rank.resize(n);
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
        if (rank[rx] < rank[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (rank[rx] == rank[ry]) {
            rank[rx] += 1;
        }
    }
}

namespace DJ2 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
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
        fa[ry] = rx;
    }

    void merger(int x, int y) {
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
            ra[rx] += 1;
        }
        return;
    }
}

namespace DJ3 {
    vector<int> fa;
    vector<int> ra;
    int n;

    void init(int nn) {
        n  = nn;
        fa.resize(n);
        ra.resize(n);
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
        fa[ry] = rx;
    }

    void merger(int x, int y) {
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
            ra[rx] += 1;
        }
        return;
    }
}

namespace DJ_4 {
    vector<int> fa;
    int n;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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
        fa[ry] = rx;
    }
}

namespace DJ_5 {
    int n;
    vector<int> fa;
    vector<int> ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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

namespace DJ_6 {
    int n;
    vector<int> fa;
    vector<int> ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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
            ra[rx] += 1;
        }
    }
}

namespace DJ_7 {
    int n;
    vector<int> fa;
    vector<int> ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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
            ra[rx] += 1;
        }
    }
}

namespace DJ_8 {
    int n;
    vector<int> fa;
    vector<int> ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            ra[i] = 1;
        }
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

namespace DJ_9 {
    int n;
    vector<int> fa, ra;
    void init(int nn) {
        n = nn;
        iota(fa.begin(), fa.end(), 0);
        ra.resize(n, 1);
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_10 {
    int n;
    vector<int> fa;
    vector<int> ra;
    void init(int nn) {
        n = nn;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            ra[i] = 1;
        }
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) swap(rx, ry);
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) ra[rx]++;
    }
};

namespace DJ_11 {
    int n;
    vector<int> fa;
    vector<int> ra;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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

namespace DJ_12 {
    vector<int> fa, ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) swap(rx, ry);
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_13 {
    vector<int> fa;
    vector<int> ra;
    vector<int> sz;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
        sz.resize(n);
        iota(fa.begin(), fa.end(), 0);
        fill(sz.begin(), sz.end(), 1);
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        sz[rx] += sz[ry];
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_14 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n + 1);
        ra.resize(n + 1);
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
        int ry = find(y);
        if (rx == ry) return;
        fa[ry] = rx;
        if (ra[x] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_15 {
    vector<int> fa,ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
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
        if (rx == ry) return;
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
}

namespace DJ_16 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_17 {
    vector<int> fa, ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            fa[rx]++;
        }
    }
}

namespace DJ_18 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_19 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
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
        if (rx == ry) return;
        if (ra[ry] > ra[rx]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_20 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
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
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_21 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n);
        ra.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
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

namespace DJ_22 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
        fa.resize(n + 1);
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

namespace DJ_23 {
    vector<int> fa;
    vector<int> ra;
    int n;
    void init(int _n) {
        n = _n;
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
        if (rx == ry) return;
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
        fa[ry] = rx;
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }
}

namespace DJ_24 {
    vector<int> fa, ra;
    int n;
    void init(int _n) {
        n = _n;
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
        if (ra[rx] == ra[ry]){
            ra[rx]++;
        }
    }
}
namespace DJ_25 {
    vector<int> fa;
    void init(int n) {
        fa.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x != fa[x]){
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        fa[y] = x;
    }
}
namespace DJ_26 {
    vector<int> fa;
    void init(int n) {
        fa.resize(n);
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
        fa[ry] = rx;
    }
}

namespace DJ_27 {
    int n;
    vector<int> fa;
    void init(int nn) {
        n = nn;
        fa.resize(n);
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
        fa[ry] = rx;
    }

}

int main() {
    vector<int> nums = {1,2,2,3,3,4};
    cout << nums.size() << endl;

    nums.resize(8);
    cout << nums.size() << endl;
    for (auto e : nums) {
        cout << e << " ";
    }
    cout << endl;

    nums.clear();
    cout << nums.size() << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
