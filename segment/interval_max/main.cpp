//
// Created by liguoyang on 2023/3/1.
//

#include "../../sum.h"
namespace SEG_INTERVAL_MAX_1 {
    int f[40010];
    int z[40010];
    void init() {
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
    }

    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            f[o] = u;
            z[o] = u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] = z[o];
            f[o * 2 + 1] = z[o];
            z[o * 2] = z[o];
            z[o * 2 + 1] = z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = max(f[o * 2], f[o * 2 + 1]);
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] = z[o];
            f[o * 2 + 1] = z[o];
            z[o * 2] = z[o];
            z[o * 2 + 1] = z[o];
            z[o] = 0;
        }
        if (L <= m) {
            ans = max(ans, ask(o * 2, l, m, L, R));
        }
        if (R > m) {
            ans = max(ans, ask(o * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
}


int main() {

}
