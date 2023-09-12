#include <iostream>
#include <vector>
using namespace std;

namespace GCD_1 {
    int gcd(int x, int y) {
        if (x == 0) {
            return y;
        }
        return gcd(y % x, x);
    }
    int binary_gcd(int x, int y) {
        return 0;
    }
}

namespace GCD_2 {
    int gcd(int x, int y) {
        if (x == 0) {
            return y;
        }
        return gcd(y % x, x);
    }
    int gcd2(int x, int y) {
        if (x > y) swap(x, y);
        if (x == 0) {
            return y;
        }
        return gcd2(y - x, x);
    }
}


using GCD_2::gcd;
void test_gcd() {
    cout << gcd(21, 21) << endl;
}
int main() {
    test_gcd();
    return 0;
}
