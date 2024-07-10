//
// Created by yex on 2023/3/24.
//

#include "../../sum.h"
namespace MANACHER_1 {
    vector<int> get_d1(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                r = i + k;
                l = i - k;
            }
        }
        return d;
    }
    vector<int> get_d2(string s) {
        int n = s.size();
        vector<int> d(n);
        d.back() = 1;
        d.begin() = 1;
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(d[l + r - i], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                r = i + k;
                l = i - k - 1;
            }
        }
        return d;
    }
}

namespace MANACHER_2 {
    vector<int> get_d1(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                r = i + k;
                l = i - k;
            }
        }
        return d;
    }
    vector<int> get_d2(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(d[l + r - i], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                r = i + k;
                l = i - k - 1;
            }
        }
        return d;
    }
}

using MANACHER_2::get_d1;
using MANACHER_2::get_d2;
string shortestPalindrome(string s) {
    int n = s.size();
    auto d1 = get_d1(s);
    auto d2 = get_d2(s);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (d1[i] == i + 1) {
            pos = max(pos, i + d1[i]);
        }
        if (d2[i] == i) {
            pos = max(pos, i + d2[i]);
        }
    }
    string t = s.substr(pos, n - pos);
    reverse(t.begin(), t.end());
    return t + s;
}

void test() {
    string s;
    // ans: aaacecaaa
    s = "aacecaaa";
    cout << shortestPalindrome(s) << endl;

    // ans: dcbabcd
    s = "abcd";
    cout << shortestPalindrome(s) << endl;
}

int main() {
    test();
}