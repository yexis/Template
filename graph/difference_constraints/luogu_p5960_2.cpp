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

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

/*
 * 最短路：spfa算法，基于松弛操作的单源最短路算法，Bellman-Ford算法的优化版本
 * 每轮只访问上一轮更新过的点，因为只有上一轮被更新过的点，这一轮才有可能被更新
 * 使用队列进行维护；
 * vis[u]记录u点是否在队内；
 * cnt[v]记录边数，判负权环
 * 
 * 
 * 差分约束系统求解不等式组有两种方法：最短路和最长路
 * - 求最大解：a - b <= c，跑最短路，判负环
 * - 求最小解：a - b >= c，跑最长路，判正环
 * 
 * 在固定参考变量、系统可行且相应极值有界的前提下：
 * - 最短路求的是各变量相对于参考变量的最大可行差值，即最大解。
 * - 最长路求的是各变量相对于参考变量的最小可行差值，即最小解。
 * 
 * a <= b + c; 最大解，跑最短路，判负环：
 *     a <= -1 不成立
 *     a = 0
 *      ○ --3--→ ○ b <= 3
 *      ↑        |
 *      |-7      | 2
 *      |        ↓
 *      ○ ←--1-- ○ c <= 5
 *      d <= 6
 *    根据上图，存在负环时，初始a=0出发，经过环后得出a的约束 a <= -1，明显不成立
 * 
 * a >= b + c; 最小解，跑最长路，判正环：
 *     a >= 1 不成立
 *     a = 0
 *      ○ --3--→ ○ b >= 3
 *      ↑        |
 *      |-5      | 2
 *      |        ↓
 *      ○ ←--1-- ○ c >= 5
 *      d >= 6
 *    根据上图，存在负环时，初始a=0出发，经过环后得出a的约束 a >= 1，明显不成立
*/


// SPFA
// 添加超级源点版本
struct SPFA {
    // 点数，边数
    int n, m;
    vector<pii> edges;
    vector<vector<pii>> g;
    vector<int> d, cnt, vis, pre;
    SPFA(int nn, int mm) {
        // 实则是n+1个点，m+n条边
        n = nn, m = mm;
        g.resize(n);
        // 注意：d的初始化，最短路和最长路
        d.resize(n, INF); cnt.resize(n);
        vis.resize(n); pre.resize(n);
    }
    void add_edge(int u, int v, int w) {
        edges.push_back(pii(u, v));
        g[u].push_back(pii(v, w));
    }
    // a - b <= c，最短路，求最大解
    // 返回true，表示有负环
    // 返回false，表示无负环
    bool spfa(int s) {
        queue<int> q;
        q.push(s); vis[s] = true; d[0] = 0;
        while (q.size()) {
            auto u = q.front(); q.pop(); vis[u] = false;
            for (auto& [v, w] : g[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w; 
                    cnt[v] = cnt[u] + 1;
                    pre[v] = u;
                    if (cnt[v] >= n) {
                        return true;
                    }
                    if (!vis[v]) {
                        q.push(v); vis[v] = true;
                    }
                }
            }
        }
        return false;
    }

    // a - b >= c，最长路，求最大解
    // 返回true，表示有正环
    // 返回false，表示无正环
    bool spfa2() {
        return false;
    }
 };

void solve() {
    int n, m; cin >> n >> m;

    SPFA spfa(n + 1, m + n);
    // 为了能走到所有点，设置超级源点，连接到所有点
    for (int i = 0; i < n; i++) {
        spfa.add_edge(0, i + 1, 0);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        spfa.add_edge(v, u, w); // u - v <= w
    }

    bool ok = spfa.spfa(0);
    if (ok) {
        cout << "NO" << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << spfa.d[i] << " ";
    }
    cout << "\n";

}


int main() {
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();    
    }
    return 0;
}