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

// ----------单点------------
void test() {
    // ans : 22
    using BIT_12::init;
    using BIT_12::add;
    using BIT_12::ask;
    init(101);
    add(1, 2);
    add(10, 20);
    add(100, 200);
    cout << "12 单点 ans : " << ask(10) << endl;
}

// ----------区间-----------
void test_lr() {
    using BIT_15::init;
    using BIT_15::add_lr;
    using BIT_15::ask_lr;

    // ans : 12
    init(100);
    add_lr(1, 10, 1);
    add_lr(3, 5, 2);
    add_lr(3, 3, 3);
    add_lr(99, 101, 10);
    cout << "15 区间 ans : " << ask_lr(3, 5) << endl;
}

int main() {
    test();
    test_lr();
    return 0;
}
