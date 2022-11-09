#include <iostream>
#include <vector>
using namespace std;

namespace SEG {
    int f[400001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] = u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }

        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG2 {
    int f[40001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2 + 1, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_MAX {
    int f[400001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = max(f[o * 2], f[o * 2 + 1]);
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >=r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans = max(ans, ask(o * 2, l, m, L, R));
        }
        if (R > m) {
            ans = max(ans, ask(o * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
}

namespace SEG_2 {
    int f[400001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (l <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }

        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SET_3 {
    int f[40001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}


namespace MAX_3 {
    int f[400001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }

        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = max(f[o * 2], f[o * 2 + 1]);
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans = max(ans, ask(o * 2, l, m, L, R));
        }
        if (R > m) {
            ans = max(ans, ask(o * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
}

namespace SEG_4{
    int f[40001];

    void add(int o, int l, int r, int i, int u) {
        if (l == r ) {
            f[i] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m , i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o *  2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}


namespace SEG_5 {
    int f[4000001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_6 {
    int f[4000001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r ) {
            return f[o];
        }
        int m = (l + r) >> 1;
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

namespace SEG_7 {
    int f[400001];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_8 {
    int f[400010];
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_9 {
    int f[4000010];
    void init() {
        memset(f, 0, sizeof(f));
    }
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_10 {
    int f[40010];
    void init() {
        memset(f, 0, sizeof(f));
    }
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}

namespace SEG_11 {
    int f[40010];
    void init() {
        memset(f, 0, sizeof(f));
    }
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            f[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
}


void test();
int main() {
    test();
    return 0;
}

using SEG_11::init;
using SEG_11::add;
using SEG_11::ask;
void test() {
    SEG_10::init();
    add(1, 1, 10001, 1, 2);
    add(1, 1, 10001, 10, 20);
    add(1, 1, 10001, 100, 200);
    cout << ask(1, 1, 10001, 99, 10001) << endl;
}
