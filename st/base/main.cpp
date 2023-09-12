#include "../../main.h"

/*
 * 思路:
 * st 表基于倍增的思想，可以做到O(nlogn)预处理，O(1)回答每个查询。但是不支持修改操作
 *
 * 状态:
 * 令f[i][j] 表示区间[i, i + 2 ^ j - 1] 的最大值
 *
 * 条件:
 * 可重复贡献的问题，即对于opt操作，两个区间有重复的部分，但是最终opt(x,y)结果不受影响，opt(x, y) = opt(x + y)
 * 如: 区间最值、区间gcd、区间按位或，区间按位与
 *
 * 预处理部分:
 * 状态转移方程: f[i][j] = max(f[i][j - 1], f[i + 2 ^ j][j - 1])
 *
 * 询问部分:
 *
 */
namespace ST_1 {
    // Log > log(n)
    constexpr static int Log = 18;
    int n;
    int st[100005][Log];
    vector<int> a;
    // 预处理
    void init(vector<int>& aa) {
        n = aa.size();
        a = aa;
        memset(st, 0, sizeof(st));
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < Log; j++) {
            for (int i = 0; i + (1 << (j - 1)) < n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ask(int l, int r) {
        int s = ceil(log2(r - l + 1)) - 1;
        return max(st[l][s], st[r - (1  << s) + 1][s]);
    }
}

const int inf = 1e9;
namespace ST_2 {
    const int maxn = 100010;
    const int Log = 18;
    int n;
    int st[maxn][Log];
    vector<int> ob;
    void init() {
        n = ob.size();
        for (int i = 0; i < n; i++) {
            st[i][0] = ob[i];
        }
        for (int j = 1; j < Log; j++) {
            for (int i = 0; i + (1 << (j - 1)) < n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ask(int l, int r) {
        if (l > r) return -inf;
        int len = r - l + 1;
        int s = floor(log2(len));
        return max(st[l][s], st[r - (1 << s) + 1][s]);
    }
}

namespace ST_3 {
    const int maxn = 100010;
    int n;
    vector<vector<int>> st;
    void init(int nn, vector<int>& a) {

    }
}

using namespace ST_2;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& a, int k) {
        n = a.size();
        int ans = -inf;

        ob.clear();
        for (int i = 0; i < n; i++) {
            ob.emplace_back(a[i][1] - a[i][0]);
        }
        init();

        for (int i = 0; i < n; i++) {
            int x = a[i][0], y = a[i][1];
            int sum = y + x;
            int l = lower_bound(a.begin(), a.end(), x, [&](const auto& aa, const int& bb) {
                return aa[0] + k < bb;
            }) - a.begin();
            if (l == i) continue;
            ans = max(ans, sum + ask(l, i - 1));
        }

        return ans;
    }

    void test() {
        vector<vector<int>> a;
        int k;
        a = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
        k = 1;
        cout << findMaxValueOfEquation(a, k) << endl;

        a = {{0, 0}, {3, 0}, {9, 2}};
        k = 3;
        cout << findMaxValueOfEquation(a, k) << endl;
    }
};

int main() {
    Solution s;
    s.test();
}