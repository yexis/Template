//
// Created by yex on 2023/3/24.
//
#include "../../sum.h"
namespace KMP_1 {
    vector<int> kmp(string s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[j] != s[i]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) j++;
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_2 {
    vector<int> kmp(string s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) j++;
            p[i] = j;
        }
        return p;
    }
}

void test() {
    using KMP_2::kmp;
    // ans: 0 0 0 1 2 3
    string s = "abcabc";
    auto p = kmp(s);
    for (auto e : p) {
        cout << e << " ";
    }
    cout << endl;
}
int main() {
    test();
}
