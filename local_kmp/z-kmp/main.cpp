//
// Created by yex on 2023/5/6.
//

#include "../../sum.h"

namespace Z_1 {
    vector<int> z_kmp(string& s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            z[i] = max(0, min(z[i - l], r - i + 1));
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i;
                r = i + z[i] - 1;
                z[i]++;
            }
        }
        return z;
    }
}

using Z_1::z_kmp;
void test() {

}

int main() {
    test();
}