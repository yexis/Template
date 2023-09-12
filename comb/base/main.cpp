#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

namespace C_1 {
    const int maxn = 10005;
    ll c[maxn][maxn];
    void init() {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < maxn; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j] +  c[i - 1][j - 1];
                c[i][j] %= mod;
            }
        }
    }
    int C(int n, int m) {
        return c[n][m];
    }
}

namespace C_2 {
    const int maxn = 10005;
    // fac[i] : 记录i的阶乘
    // inv[i] : 记录i的阶乘在模mod下的逆元
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }

    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) return 0;
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_3 {
    const int maxn = 10005;
    ll c[maxn][maxn];
    void init() {

        for (int i = 0; i < maxn; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || m > n) {
            return 0;
        }
        return c[n][m];
    }
}

namespace C_4 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while(p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));

        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || m > n) return 0;
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_7 {
    const int maxn = 10005;
    vector<vector<int>> c(maxn, vector<int>(maxn));
    void init() {
        for (int i = 0; i < maxn; i++) {

            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || m > n) {
            return 0;
        }
        return c[n][m];
    }
}

namespace C_6 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));

        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[n - m] % mod * inv[m] % mod;
    }
}

namespace C_8 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_10 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        ll p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_12 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_13 {
    const int maxn = 10005;
    vector<vector<ll>> c(maxn, vector<ll>(maxn));
    void init() {
        for (int i = 0; i < maxn; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= mod;
            }
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return c[n][m];
    }
}

namespace C_14 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get_inv(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = 1;
        for (int i = 1; i < maxn; i++) {
           fac[i] = fac[i - 1] * i % mod;
           inv[i] = get_inv(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_15 {
    const int maxn = 10005;
    vector<vector<int>> c;
    void init() {
        c.resize(maxn);
        for (int i = 0; i < maxn; i++) {
            c[i].resize(maxn);
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= mod;
            }
        }
    }
    int C(int n, int m) {
        if (n < 0 or m < 0 or n < m) {
            return 0;
        }
        return c[n][m];
    }
}

namespace C_16 {
    static constexpr int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get(ll x) {
        ll ans = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            p >>= 1;
        }
        return ans;
    }
    void init() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get(fac[i]);
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace C_17 {
    const int mod = 1e9 + 7;
    const int maxn = 10005;
    using ll  = long long;
    vector<vector<ll>> c;
    void init() {
        c.resize(maxn);
        for (int i = 0; i < maxn; i++) {
            c[i].resize(maxn);
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= mod;
            }
        }
    }
    int C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return c[n][m];
    }
}
using ll = long long;
namespace C_18 {
    static constexpr int maxn = 10005;
    vector<vector<ll>> c;
    void init() {
        c.resize(maxn);
        for (int i = 0; i < maxn; i++) {
            c[i].resize(maxn);
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= mod;
            }
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return c[n][m];
    }
}

namespace C_19 {
    const int maxn = 10005;
    vector<vector<ll>> c;
    void init() {
        c.resize(maxn);

        for (int i = 0; i < maxn; i++) {
            c[i].resize(maxn);
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= mod;
            }
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return c[n][m];
    }
}

namespace C_20 {
    const int maxn = 10005;
    vector<vector<ll>> c;
    void init() {
        c.resize(maxn);
        for (int i = 0; i < maxn; i++) {
            c[i].resize(maxn);
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= mod;
            }
        }
    }
    ll C(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return c[n][m];
    }
}

// ans: 448217028
// 简单
void test_easy(int n, int m) {
    using C_20::init;
    using C_20::C;
    init();
    cout << C(n, m) << endl;
}



int main() {
    test_easy(10000, 9920);
    return 0;
}
