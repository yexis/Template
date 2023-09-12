#include <iostream>
#include <vector>
using namespace std;

// lcp 计算字符串之前的最长公共前缀/后缀
// 前缀：从前往后遍历
// 后缀：从后往前遍历

namespace LCP {
    // 计算字符串s中所有 前缀子串 之间的最长公共后缀
    // 前缀子串：比如从起点开始的子串
    // eg: s = "abab" 前缀子串有 ["a", "ab", "aba", "abab"]
    bool lcp(string s, int l, int r, int len) {
        int n = s.size();
        vector<vector<int> > lc(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    lc[i][j] = lc[i + 1][j + 1] + 1;
                }
            }
        }
        return lc[l][r] >= len;
    }
}

namespace LCP_1 {
    // 如何计算字符串中两段长度的字符串是否相同
    bool lcp(string s, int l, int r, int len) {
        int n = s.size();
        int lc[n + 1][n + 1];
        memset(lc, 0, sizeof(lc));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    lc[i][j] = lc[i + 1][j + 1] + 1;
                }
            }
        }
        return lc[l][r] >= len;
    }
}

namespace LCP_2 {
    vector<vector<int> > lcp(string s, int l, int r) {
        int n = s.size();
        vector<vector<int> > lc(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    lc[i][j] = lc[i + 1][j + 1] + 1;
                }
            }
        }
        return lc;
    }
}

namespace LCP_3 {
    vector<vector<int> > lcp(string s, int l, int r) {
        int n = s.size();
        vector<vector<int> > lc(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    lc[i][j] =  lc[i + 1][j + 1] + 1;
                }
            }
        }
        return lc;
    }
}

namespace LCP_4 {
    vector<vector<int> > lcp(string s) {
        int n = s.size();
        vector<vector<int> > lc(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    lc[i][j] = lc[i + 1][j + 1] + 1;
                }
            }
        }
        return lc;
    }
}

namespace LCP_5 {
    vector<vector<int>> lcp(string s) {
        int n = s.size();
        vector<vector<int>> lc(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    lc[i][j] = lc[i + 1][j + 1] + 1;
                }
            }
        }
    }
}

namespace LCP_6 {
    vector<vector<int>> lcp(string s) {
        int n = s.size();
        vector<vector<int>> lc(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {

                }
            }
        }
    }
}



int main() {
    cout << LCP::lcp("aaaaaaa", 0, 3, 3) << endl;
    return 0;
}
