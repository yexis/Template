//
// Created by liguoyang on 2023/3/1.
//
#include <iostream>
#include <vector>
using namespace std;

namespace BIT_INTERVAL_1 {
    int n;
    vector<int> tree, assi;
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
            ans +=  x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_INTERVAL_2 {
    vector<int> tree, assi;
    int n;
    void init(int _n) {
        n = _n;
        tree.resize(n + 1);
        assi.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
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
        for (int i = x; i > 0; i -= lb(i)) {
            ans += x * tree[i] - assi[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask_lr(y) - ask_lr(x - 1);
    }
}

namespace BIT_INTERVAL_3 {
    int n;
    vector<int> tr, as;
    void init(int nn) {
        n = nn;
        tr.resize(n + 1);
        as.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add_lr(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
            as[i] += (x - 1) * u;
        }
    }
    int add_lr(int x, int y, int u) {
        add_lr(x, u);
        add_lr(y + 1, -u);
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += x * tr[i] - as[i];
        }
        return ans;
    }
    int ask_lr(int x, int y) {
        return ask(y) - ask(x - 1);
    }
}


void test() {
    using BIT_INTERVAL_3::init;
    using BIT_INTERVAL_3::add_lr;
    using BIT_INTERVAL_3::ask_lr;

    // ans : 12
    init(100);
    add_lr(1, 10, 1);
    add_lr(3, 5, 2);
    add_lr(3, 3, 3);
    add_lr(99, 101, 10);
    cout << "BIT_INTERVAL ans : " << ask_lr(3, 5) << endl;
}

int main() {
    test();
}