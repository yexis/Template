//
// Created by liguoyang on 2023/3/16.
//
#include "../../main.h"

namespace KMP_1 {
    vector<int> kmp(string& s) {
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

namespace KMP_2 {
    vector<int> kmp(string s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_3 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_4 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_5 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_6 {
    vector<int> kmp(string& s) {
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

namespace KMP_7 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_8 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_9 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_10 {
    vector<int> kmp(string s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
}

namespace KMP_11 {
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }

    // 判断循环字符串 s 中是否包含字符串 t
    // 也就是说字符串s中的任意位置都可以作为起点，判断s == t
    vector<int> search(string& s, string& t) {
        vector<int> res;

        int n = s.size(), m = t.size();
        // pattern放前面，text放后面
        string ss = t + "#" + s + s.substr(0, n - 1);

        auto p = kmp(ss);
        for (int i = m + 1; i < ss.size(); i++) {
            if (p[i] >= m) {
                res.push_back(i - 2 * m);
            }
        }
        return res;
    }
}

using KMP_11::kmp;
using KMP_11::search;
void test() {
    string s;
    // ans: 0 0 0 0 0 1 2 3 4 5 6 7
    s = "abcdbabcdbab";
    auto res = kmp(s);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;
}

void test2() {
    string s = "abcd", t = "cdab";
    auto d = search(s, t);
    for (auto& e : d) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    test();
    test2();
}