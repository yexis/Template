//
// Created by liguoyang on 2023/2/28.
//

#include "../../sum.h"

namespace SEG_INTERVAL_1 {
    int f[40010];
    int z[40010];
    void init() {
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            f[o] += (r - l + 1) * u;
            z[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] +=  z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] +=  z[o];
            z[o] = 0;
        }
        int ans = 0;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_INTERVAL_2 {
    int f[40010];
    int z[40010];
    void init() {
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            f[o] += (r - l + 1) * u;
            z[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] += z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] += z[o];
            z[o] = 0;
        }
        int ans = 0;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_INTERVAL_3 {
    int f[40010];
    int z[40010];
    void init() {
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            f[o] += (r - l + 1) * u;
            z[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] += z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] += z[o];
            z[o] = 0;
        }
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_INTERVAL_4 {
    int f[40010];
    int z[40010];
    void init() {
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            f[o] += u * (r - l + 1);
            z[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] +=  (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] += z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] +=  (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] += z[o];
            z[o] = 0;
        }
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}