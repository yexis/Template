//
// Created by yex on 2023/10/29.
//

#include "../../sum.h"
// from
// LeetCode 116场双周赛 T4

using ll = long long;
const int mod = 1e9 + 7;

namespace SEG_INTERVAL_ADD_X2_1 {
    ll f[400010]; // 区间和
    ll g[400010]; // 平方和
    ll z[400010];
    void init() {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            g[o] += 2 * u * f[o] + (r - l + 1) * u * u;
            g[o] %= mod;
            f[o] += (r - l + 1) * u;
            f[o] %= mod;
            z[o] += u;
            z[o] %= mod;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            g[o * 2] += 2 * z[o] * f[o * 2] + (m - l + 1) * z[o] * z[o];
            g[o * 2] %= mod;
            g[o * 2 + 1] += 2 * z[o] * f[o * 2 + 1] + (r - m) * z[o] * z[o];
            g[o * 2 + 1] %= mod;
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2] %= mod;
            f[o * 2 + 1] += (r - m) * z[o];
            g[o * 2] %= mod;
            z[o * 2] += z[o];
            z[o * 2] %= mod;
            z[o * 2 + 1] += z[o];
            z[o * 2 + 1] %= mod;

            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
        f[o] %= mod;
        g[o] = g[o * 2] + g[o * 2 + 1];
        g[o] %= mod;
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return g[o];
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            g[o * 2] += 2 * z[o] * f[o * 2] + (m - l + 1) * z[o] * z[o];
            g[o * 2] %= mod;
            g[o * 2 + 1] += 2 * z[o] * f[o * 2 + 1] + (r - m) * z[o] * z[o];
            g[o * 2 + 1] %= mod;
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2] %= mod;
            f[o * 2 + 1] += (r - m) * z[o];
            f[o * 2 + 1] %= mod;
            z[o * 2] += z[o];
            z[o * 2] %= mod;
            z[o * 2 + 1] += z[o];
            z[o * 2 + 1] %= mod;
            z[o] = 0;
        }
        int ans = 0;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
            ans %= mod;
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
            ans %= mod;
        }
        return ans;
    }
};

using namespace SEG_INTERVAL_ADD_X2_1;

class Solution {
public:
    int sumCounts(vector<int>& a) {
        init();

        int n = a.size();
        ll ans = 0;
        vector<int> L(1e5 + 5, -1);
        for (int i = 0; i < n; i++) {
            add(1, 1, n, max(0, L[a[i]] + 1) + 1, i + 1, 1);
            ans += ask(1, 1, n, 1, i + 1);
            ans %= mod;
            L[a[i]] = i;
        }
        return ans;
    }
    void test() {
        vector<int> nums;
        // 15
        nums = {1,2,1};
        cout << sumCounts(nums) << endl;

        // 3
        nums = {2, 2};
        cout << sumCounts(nums) << endl;

    }
};

int main() {
    Solution so;
    so.test();
}
