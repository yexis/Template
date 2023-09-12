#include <iostream>
using namespace std;
using ll = long long;
static constexpr int mod = 1e9 + 7;


namespace QB {
    long long quick_power(int n, int b) {
        long long ans = 1l;
        long long x = n;
        while (x) {
            if (b & 1) {
                ans *= x;
            }
            b >>= 1;
            x *= x;
        }
        return ans;
    }

    void test() {
        using QB::quick_power;
        cout << quick_power(2, 51) << endl;
    }
}

namespace QS_2 {
    long long quick_power(int n, int b) {
        long long ans = 1l;
        long long x = n;
        while (b) {
            if (b & 1) {
                ans *= x;
            }
            b >>= 1;
            x *= x;
        }
        return ans;
    }

    double quick_sort_ne(double n, int b) {
        double ans = 1.0f;
        double x = n;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        while (b) {
            if (b & 1) {
                ans *= x;
                cout << ans << endl;
            }
            b >>= 1;
            x *= x;
        }
        return ans;
    }
}

namespace QB_3 {
    ll quick_power(int n, int b) {
        int x = n;
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans *= x;
            }
            x *= x;
            b >>= 1;
        }
        return ans;
    }

    double quick_power_db(int n, int b) {
        double x = n;
        double ans = 1;
        if (b < 0) {
            x = 1.0f / n;
            b = -b;
        }
        while (b) {
            if (b & 1) {
                ans *= x;
            }
            x *= x;
            b >>= 1;
        }
        return ans;
    }
}

namespace QB_4 {
    ll quick_power(ll x, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            b >>= 1;
        }
        return ans;
    }
}

namespace QB_5 {
    ll quick_power(ll x, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            b >>= 1;
        }
        return ans;
    }
}

namespace QB_6 {
    ll quick_power(ll x, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            b >>= 1;
        }
        return ans;
    }
}

namespace QB_7 {
    ll quick_power(ll x, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans *= x;
                ans %= mod;
            }
            x *= x;
            x %= mod;
            b >>= 1;
        }
        return ans;
    }
}

using QB_7::quick_power;
using QB_3::quick_power_db;
void test() {
    auto ans = quick_power(2, 32);
    cout << ans << endl;
}

int main() {
    test();
    return 0;
}
