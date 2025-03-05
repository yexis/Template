//
// Created by liguoyang on 2023/3/7.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 费马小定理
 * 费马小定理计算组合数 
 * 适用于模数为质数的情况
*/

typedef long long ll;
constexpr int mod = 1e9 + 7;
namespace CC_1 {
    const int mxn = 1e5 + 5;
    ll fac[mxn], inv[mxn];
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
        for (int i = 1; i < mxn; i++) {
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

namespace CC_2 {
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

namespace CC_3 {
    const int maxn = 100005;
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

namespace CC_4 {
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
        if (m < 0 || n < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace CC_5 {
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
        return fac[n] * inv[n - m] % mod * inv[m] % mod;
    }

}

namespace CC_6 {
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

namespace CC_7 {
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


namespace CC_8 {
    const int maxn = 10005;
    ll fac[maxn], inv[maxn];
    ll get(ll x) {
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


using CC_8::init;
using CC_8::C;
void test() {
    // ans: 448217028
    int n = 10000, m = 9920;
    init();
    cout << C(n, m) << endl;
}

int main() {
    test();
}