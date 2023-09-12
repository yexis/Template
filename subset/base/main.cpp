#include <iostream>
#include <vector>
using namespace std;

namespace SUB_1 {
    void get(int n) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int subset = mask; subset; subset = (subset - 1) & mask) {
                // subset 则是 mask 的所有二进制子集
            }
        }
    }
}

namespace SUB_2 {
    void get(int n) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int sub = mask; sub; sub = (sub - 1) & mask) {

            }
        }
    }
}

namespace SUB_3 {
    void get(int n) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int sub = mask; sub; sub = (sub - 1) & mask) {

            }
        }
    }
}

namespace SUB_4 {
    void get(int n) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int sub = mask; sub; sub = (sub - 1) & mask) {

            }
        }
    }
}

void test() {
    int a = 10;
    int* const b = &a;
    *b = 100;
    cout << *b << endl;
}

int main() {
    test();
    return 0;
}
