#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <limits>
#include <climits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";


/*
 * 线性DP
 * 斜率优化DP 上凸包 | 下凸包
 * https://leetcode.cn/problems/minimum-cost-to-divide-array-into-subarrays/
*/


/*
f[i] = f[j] + s1[i] * s2[i] - s1[i] * s2[j] + K * s2[n] - K * s2[j]
=> f[j] - K * s2[j] = s1[i] * s2[j] + f[i] - s1[i] * s2[i] - K * s2[n]

y = kx + b; 下凸包，i作为常量，j作为变量
y = f[j] - K * s2[j]
k = s1[i]
x = s2[j]
b = f[i] - s1[i] * s2[i] - K * s2[n]
*/

// 模板部分 开始
using ll = long long;
struct Point {
    ll x, y, idx; // idx表示转移来源的下标，便于查问题
    Point operator+(const Point& that) {
        return {x + that.x, y + that.y, -1};
    }
    Point operator-(const Point& that) {
        return {x - that.x, y - that.y, -1};
    }
    // 方法一：将 y1 / x1 < y2 / x2 转换成乘法 y1 * x2 < y2 * x1
    // 说明：此处的 lhs 和 rhs 中的 x/y 代表的是 dx/dy
    // 前提：需要满足 dx >= 0
    // < 0: 说明 lhs的斜率 小于 rhs 的斜率
    // = 0: 说明 lhs的斜率 等于 rhs 的斜率
    // > 0: 说明 lhs的斜率 大于 rhs 的斜率
    friend ll cross(Point lhs, Point rhs) {
        return lhs.y * rhs.x - lhs.x * rhs.y;
    }
 	  // 方法二：直接计算斜率，不要求dx > 0，但是double会有精度问题，判断斜率时不要使用=符号，使用 > 和 <
    friend double slope(Point lhs, Point rhs) {
        return lhs.x == rhs.x ? 1e9 : (lhs.y - rhs.y) / (lhs.x - rhs.x);
    }
};
// 模板部分 结束

/*
 * 使用斜率优化需要满足斜率是单调的，单调增（下凸包） 或者 单调减（上凸包） 都可以
*/

class Solution {
public:
    long long minimumCost(vector<int>& a, vector<int>& b, int K) {
        int n = a.size();
        vector<ll> s1(n + 1); 
        vector<ll> s2(n + 1); 
        for (int i = 0; i < n; i++) {
            s1[i + 1] = s1[i] + a[i];
            s2[i + 1] = s2[i] + b[i];
        }

        ll dp[n + 1];
        memset(dp, 0, sizeof(dp));
        /*
        y = kx + b; 下凸包，i作为常量，j作为变量
        y = f[j] - K * s2[j]
        k = s1[i]
        x = s2[j]
        b = f[i] - s1[i] * s2[i] - K * s2[n]
        */

        deque<Point> q;
        for (int i = 1; i <= n; i++) {
            // 更新队尾 (x, y)
            Point lst(s2[i - 1], dp[i - 1] - K * s2[i - 1], i - 1);
            // （踩坑）这里一定要注意：需要满足队列尾部相邻节点的斜率 需要 大于 新节点和尾部节点的斜率 才需要出队，因为这样不满足下凸包
            while (q.size() >= 2 && cross(q[q.size() - 1] - q[q.size() - 2], lst - q[q.size() - 1]) >= 0) {
                q.pop_back();
            }
            q.push_back(lst);

            // 更新队首 k_i
            Point p_k = {1, s1[i], -1};
            while (q.size() >= 2 && cross(q[1] - q[0], p_k) <= 0) {
                q.pop_front();
            }
            
            // 得到答案 队首就是最优决策点
            Point& pj = q.front();
            dp[i] = cross(pj, p_k) + s1[i] * s2[i] + K * s2[n];
        }
        return dp[n];
    }
};
