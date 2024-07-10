//
// Created by liguoyang on 2023/3/21.
//
#include "../../sum.h"

namespace MANACHER_1 {
    vector<int> cal_d(string& s) {
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
    vector<int> cal_dd(string& s) {
        int n = s.size();
        vector<int> dd(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(dd[l + r - i], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            dd[i] = k--;
            if (i + k > r) {
                r = i + k;
                l = i - k - 1;
            }
        }
        return dd;
    }
}

namespace MANACHER_2 {
    vector<int> cal_d1(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = l > r ? 1 : min(d[l + r - i], r - i + 1);
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

    vector<int> cal_d2(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = l > r ? 0 : min(d[l + r - i], r - i + 1);
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

namespace MANACHER_3 {
    vector<int> cal_d1(string& s) {
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
    vector<int> cal_d2(string& s) {
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

namespace MANACHER_4 {
    vector<int> cal_d1(string& s) {
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
    vector<int> cal_d2(string& s) {
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

namespace MANACHER_5 {
    vector<int> cal_d1(string& s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return d;
    }
    vector<int> cal_d2(string& s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(d[l + r - i], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
        return d;
    }
}

namespace MANACHER_6 {
    vector<int> cal_d1(string& s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
    }
    vector<int> cal_d2(string& s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(d[l + r - i], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
    }

}

namespace MANACHER_7 {
    vector<int> cal_d1(string& s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(r - i + 1, d[l + r - i]);
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
    vector<int> cal_d2(string& s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(r - i + 1, d[l + r - i]);
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

namespace MANACHER_8 {
    vector<int> cal_d1(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 : min(r - i + 1, d[l + r - i]);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return d;
    }
    vector<int> cal_d2(string s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(r - i + 1, d[l + r - i]);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
        return d;
    }
}


using MANACHER_8::cal_d1;
using MANACHER_8::cal_d2;

void test() {
    string s = "acbaabcaa";
    auto d = cal_d1(s);
    auto dd = cal_d2(s);

    // 1 1 1 1 1 1 1 1 1
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    // 0 0 0 0 4 0 0 0 1
    for (int i = 0; i < dd.size(); i++) {
        cout << dd[i] << " ";
    }
    cout << "\n";
}

int main() {
    test();
}