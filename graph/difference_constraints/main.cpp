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
 * - a - b <= c，跑最短路，判负环
 * - a - b >= c，跑最长路，判正环
 * 
 * 在固定参考变量、系统可行且相应极值有界的前提下：
 * - 最短路求的是各变量相对于参考变量的最大可行差值。
 * - 最长路求的是各变量相对于参考变量的最小可行差值。
 * 
*/

struct DifferenceConstraints {
    // 点数，边数
    int n, m;
    vector<pii> edges;
    vector<vector<pii>> g;
    vector<int> d, cnt, vis, pre;
    DifferenceConstraints(int nn, int mm) {
        n = nn, m = mm; 
        g.resize(n); init();
    }
    void init() {
        d.assign(n, INF); cnt.assign(n, 0);
        vis.assign(n, 0); pre.assign(n, 0);
    }
    void add_edge(int u, int v, int w) {
        edges.push_back(pii(u, v));
        g[u].push_back(pii(v, w));
    }
    // a - b <= c，最短路，求最大解
    // 返回true，表示有负环， false表示无负环
    // s >= n 全源判负环; s < n 无负环，最短路找最大解
    bool spfa(int s) {
        int n = g.size();
        
        queue<int> q;
        if (s >= n) {
            for (int i = 0; i < n; i++) { 
                q.push(i); vis[i] = true; d[i] = 0; 
            }
        } else { 
            q.push(s); vis[s] = true; d[s] = 0;
        }
        
        while (q.size()) {
            auto u = q.front(); q.pop(); vis[u] = false;
            for (auto& [v, w] : g[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w; cnt[v] = cnt[u] + 1;
                    pre[v] = u;
                    if (cnt[v] >= n) return true;
                    if (!vis[v]) {
                        q.push(v); vis[v] = true;
                    }
                }
            }
        }
        return false;
    }

    // a - b >= c，最长路，求最小解
    // 返回true，表示有正环
    // 返回false，表示无正环
    bool spfa2(int s) {
        int n = g.size();
        
        queue<int> q;
        if (s >= n) {
            for (int i = 0; i < n; i++) { 
                q.push(i); vis[i] = true; d[i] = 0; 
            }
        } else { 
            q.push(s); vis[s] = true; d[s] = 0;
        }
        
        while (q.size()) {
            auto u = q.front(); q.pop(); vis[u] = false;
            for (auto& [v, w] : g[u]) {
                if (d[u] + w > d[v]) {
                    d[v] = d[u] + w; cnt[v] = cnt[u] + 1;
                    pre[v] = u;
                    if (cnt[v] >= n) return true;
                    if (!vis[v]) {
                        q.push(v); vis[v] = true;
                    }
                }
            }
        }
        return false;
    }
 };

 /*
  A[i]: i时刻需要的人数
  B[i]: i时刻到来的人数
  C[i]: i时刻雇佣的人数

  条件1：i时刻雇佣的人数需要 小于等于 到来的人数，即 C[i] <= B[i]
  条件2：从i-7到i时刻雇佣的人都能在都能在i时刻工作，即 x[i - 6] + ... + x[i + 1] >= A[i]

  求最小解，跑最长路，约束全部转化成 >=
  1. s[i + 1] - s[i] >= 0           => s[i + 1] >= s[i] + 0
  2. s[i] - s[i + 1] >= -B[i]       => s[i] >= s[i + 1] - B[i]
  3. s[i + 1] - s[i - 7] >= A[i], 7 <= i <= 23
    => s[i + 1] >= s[i - 7] + A[i]
  4. s[i + 1] + (s[24] - s[24 - (8 - (i + 1)]) >= A[i], i < 7
    => s[i + 1] - s[16 + i + 1] >= A[i] - s[24]
    => s[i + 1] >= s[16 + i + 1] >= A[i] - s[24]

  s[24]即题目所求

  二分mid，令 mid = s[24]，则有 mid <= s[24] <= mid
  5. s[24] >= mid
    => s[24] >= s[0] + mid
  6. -s[24] >= -mid
    => -s[24] >= -s[0] - mid
    => s[0] >= s[24] - mid

  答案：
  当 mid > ans 时，不等式满足，说明有解，无正环
  当 mid <= ans 时，不等式不满足，说明无解，有正环 
*/
void solve() {
    // A: 时刻i需要的人数
    vector<int> A(24, 0); for (int i = 0; i < 24; i++) cin >> A[i];
    
    int n; cin >> n;
    // B: 时刻i应聘的人数
    vector<int> B(24, 0);  
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        B[e]++;
    }

    auto check = [&](int mid) -> bool {
        DifferenceConstraints dc(25, 1000);
        for (int i = 0; i < 24; i++) {
            // cerr << i << " " << i + 1 << "\n";
            dc.add_edge(i, i + 1, 0);
            dc.add_edge(i + 1, i, -B[i]);
        }
        for (int i = 0; i < 7; i++) {
            dc.add_edge(i + 17, i + 1, A[i] - mid);
        }
        for (int i = 7; i < 24; i++) {
            dc.add_edge(i - 7, i + 1, A[i]);
        }
        dc.add_edge(0, 24, mid);
        dc.add_edge(24, 0, -mid);

        bool has = dc.spfa2(25);
        if (has) return false;
        return true;
    };

    // C: 时刻i雇佣的人数
    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (ans == -1) {
        cout << "No Solution" << "\n";
        return;
    }
    cout << ans << "\n";
}



int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();    
    }
    return 0;
}