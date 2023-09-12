//
// Created by liguoyang on 2023/5/6.
//

#include "../../main.h"

// ͳ���ַ���s�����к�׺���ַ���suf_i �� �ַ���s����Ĺ�ͬǰ׺����
namespace Z_1 {
    vector<int> z_kmp(string s) {
        int n = s.size();
        vector<int> z(n);
        int l, r;
        l = r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r && z[i - l] < r - i + 1) {
                z[i] = z[i - l];
            } else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
}


namespace Z_2 {
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
    string s;
    vector<int> z;
    // ans: [0, 4, 3, 2, 1]
    s = "aaaaa";
    z = z_kmp(s);
    for (auto& e : z) cout << e << " "; cout << endl;

    // ans: [0, 2, 1, 0, 2, 1, 0]
    s = "aaabaab";
    z = z_kmp(s);
    for (auto&e : z) cout << e << " "; cout << endl;

    // ans: [0, 0, 1, 0, 3, 0, 1]
    s = "abacaba";
    z = z_kmp(s);
    for (auto& e : z) cout << e << " "; cout << endl;
}

int main() {
    test();
}