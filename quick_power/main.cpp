#include <iostream>
using namespace std;
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

    void test() {
        auto ans = quick_sort_ne((double)1 / 2, -12);
        cout << ans << endl;
    }
}



int main() {
    QS_2::test();

    return 0;
}
