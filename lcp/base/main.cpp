#include <iostream>
#include <vector>
using namespace std;

// lcp �����ַ���֮ǰ�������ǰ׺/��׺
// ǰ׺����ǰ�������
// ��׺���Ӻ���ǰ����

namespace LCP {
    // �����ַ���s������ ǰ׺�Ӵ� ֮����������׺
    // ǰ׺�Ӵ����������㿪ʼ���Ӵ�
    // eg: s = "abab" ǰ׺�Ӵ��� ["a", "ab", "aba", "abab"]
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
    // ��μ����ַ��������γ��ȵ��ַ����Ƿ���ͬ
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
