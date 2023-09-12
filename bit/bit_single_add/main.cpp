#include <iostream>
#include <vector>
using namespace std;

namespace BIT {
    vector<int> tree;
    int n;

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }

    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }

    int ask(int x, int y) {
        return ask(y) - ask(x - 1);
    }

}

namespace BIT_2 {
    vector<int> tree;
    int n;

    void init(int nn) {
        n = nn + 1;
        tree.resize(n);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }

    int query(int x, int y) {
        return query(y) - query(x - 1);
    }
}

namespace BIT_3 {
    vector<int> tree;
    int n;

    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }

    int query(int x, int y) {
        return query(y) - query(x - 1);
    }
}

namespace BIT_4 {
    vector<int> tree;
    int n;

    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_5 {
    vector<int> tree;
    int n;
    void init(int nn) {
        n = nn + 1;
        tree.resize(n);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
    int query(int x, int y) {
        return query(y) - query(x - 1);
    }
}

namespace BIT_6 {
    vector<int> tree;
    int n;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_7 {
    vector<int> tree;
    int n;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_8 {
    vector<int> tree;
    int n;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_9 {
    vector<int> tree;
    vector<int> assi;
    int n;

    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_10 {
    vector<int> tree, assi;
    int n;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_11 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += u * (x - 1);
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_12 {
    int n;
    vector<int> tree;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_13 {
    int n;
    vector<int> tree;
    vector<int> assi;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += u * (x - 1);
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_14 {
    int n;
    vector<int> tree;
    vector<int> assi;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += u * (x - 1);
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_15 {
    int n;
    vector<int> tree;
    vector<int> assi;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += u * (x - 1);
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_16 {
    int n;
    vector<int> tree;
    vector<int> assi;
    void init(int nn) {
        n = nn;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += u * (x - 1);
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_17 {
    int n;
    vector<int> tree;
    vector<int> assi;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_18 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_19 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_20 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_21 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_22 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_23 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_24 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n);
        assi.resize(n);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_25 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_26 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n);
        assi.resize(n);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_27 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_28 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_29 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n;i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_30 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
};

namespace BIT_31 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_32 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_33 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_34 {
    vector<int> tree;
    vector<int> assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_35 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_36 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += x;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_37 {
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_38 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_40 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
            assi[i] += (x - 1) * u;
        }
    }
    void add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask_lr(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_41 {
    int n;
    vector<int> tree;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tree[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tree[i];
        }
        return ans;
    }
}

namespace BIT_42 {
    int n;
    vector<int> tr;
    void init(int nn) {
        n = nn;
        tr.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }
        return ans;
    }
}


// ----------单点------------
void test() {
    // ans : 22
    using BIT_42::init;
    using BIT_42::add;
    using BIT_42::ask;
    init(101);
    add(1, 2);
    add(10, 20);
    add(100, 200);
    cout << "BIT_37 单点 ans : " << ask(10) << endl;
}


int main() {
    test();
    return 0;
}
