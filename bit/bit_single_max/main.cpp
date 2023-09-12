//
// Created by liguoyang on 2023/3/2.
//

#include <iostream>
#include <vector>
using namespace std;

namespace BIT_SINGLE_MAX_1 {
    int n;
    vector<int> nums;
    vector<int> tree;
    void init(int _n) {
        n = _n;
        nums.resize(n + 1);
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        nums[x] = u;
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] = u;
            for (int j = 1; j < lowbit(i); j *= 2) {
                tree[i] = max(tree[i], tree[i - j]);
            }
        }
    }
    int ask(int x, int y) {
        int mx = 0;
        for (int i = y; i >= x;) {
            mx = max(mx, nums[i]);
            i--;
            while (i - lowbit(i) >= x) {
                mx = max(mx, tree[i]);
                i -= lowbit(i);
            }
        }
        return mx;
    }
}

namespace BIT_SINGLE_MAX_2 {
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

namespace BIT_SINGLE_MAX_3 {
    int n;
    vector<int> a, c;
    void init(int nn) {
        n = nn;
        a.resize(n + 1);
        c.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        a[x] = u;

        for (int i = x; i <= n; i += lb(i)) {
            c[x] = max(c[x], u);
            for (int j = 1; j < lb(i); j <<= 1) {
                c[i] = max(c[i], c[i - j]);
            }
        }
    }
    int ask(int x, int y) {
        int ans = 0;
        while (y >= x) {
            ans = max(ans, a[y]);
            y--;
            while (y - lb(y) >= x) {
                ans = max(ans, c[y]);
                y -= lb(y);
            }
        }
        return ans;
    }
}

int main() {

}
