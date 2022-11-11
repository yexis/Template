#include <iostream>
using namespace std;
using ll = long long;

namespace QS {
    long long quick_sort(int n, int b) {
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
        using QS::quick_sort;
        cout << quick_sort(2, 51) << endl;
    }
}

namespace QS_2 {
    long long quick_sort(int n, int b) {
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

namespace QS_3 {
    ll quick_sort(int n, int b) {
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

    double quick_sort_db(int n, int b) {
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

using QS_3::quick_sort;
using QS_3::quick_sort_db;
void test() {
    auto ans = quick_sort_db(2, 32);
    cout << ans << endl;
}

int main() {
    test();
    return 0;
}
