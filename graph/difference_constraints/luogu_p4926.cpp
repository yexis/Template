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
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) { ans *= x; ans %= m; }
        x *= x; x %= m; 
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
    vector<vector<pair<int, double>>> g;
    vector<double> d;
    vector<int> cnt, vis, pre;
    DifferenceConstraints(int nn, int mm) {
        n = nn, m = mm; 
        g.resize(n); init();
    }
    void init() {
        d.assign(n, 1); cnt.assign(n, 0);
        vis.assign(n, 0); pre.assign(n, 0);
    }
    void add_edge(int u, int v, double w) {
        edges.push_back(pair<int, double>(u, v));
        g[u].push_back(pair<int, double>(v, w));
    }
    // a <= b + c，最短路，求最大解
    // 返回true，表示有负环， false表示无负环
    // s >= n 全源判负环; s < n 无负环，最短路找最大解
    bool spfa(int s) {
        int n = g.size();
        
        queue<int> q;
        if (s >= n) {
            for (int i = 0; i < n; i++) { 
                q.push(i); vis[i] = true; d[i] = 1; 
            }
        } else { 
            q.push(s); vis[s] = true; d[s] = 1;
        }
        
        while (q.size()) {
            auto u = q.front(); q.pop(); vis[u] = false;
            for (auto [v, w] : g[u]) {
                if (d[u] * w < d[v]) {
                    d[v] = d[u] * w; cnt[v] = cnt[u] + 1;
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

    // a >= b + c，最长路，求最小解
    // 返回true，表示有正环
    // 返回false，表示无正环
    bool spfa2(int s) {
        int n = g.size();
        
        queue<int> q;
        if (s >= n) {
            for (int i = 0; i < n; i++) { 
                q.push(i); vis[i] = true; d[i] = 1; 
            }
        } else { 
            q.push(s); vis[s] = true; d[s] = 1;
        }
        
        while (q.size()) {
            auto u = q.front(); q.pop(); vis[u] = false;
            for (auto [v, w] : g[u]) {
                if (d[u] * w > d[v]) {
                    d[v] = d[u] * w; cnt[v] = cnt[u] + 1;
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

void solve() {
    int n, S, T; cin >> n >> S >> T;
    vector<arr4> ops;
    // 按照不需要吃顿好的 建图
    // 那么，图中存在正环，说明不满足差分约束条件，即必须有人吃顿好的
    
    // 约束条件：
    // o = 1 不吃
    // A >= B * (k - T)
    // o = 2 不吃
    // A * (k + T) > B => A >= B * 1 / (k + T)

    // 题意要求寻找最大的T，使得以上约束 不满足
    // T越小，(k - T) 和 1 / (k + T)越大，越不能满足约束    
    // 形如 0 0 0 0 0 1 1 1 1 1，找到最后一个0的T即可，二分查找
    for (int i = 0; i < S; i++) {
        int o, a, b, k; cin >> o >> a >> b >> k;
        ops.push_back({o, a, b, k});
    }
    
    vector<int> score(n + 1);
    for (int i = 0; i < T; i++) {
        int c, x; cin >> c >> x;
        score[c] = x;
    }

    auto check = [&](double mid) -> bool {
        DifferenceConstraints dc(n + 1, 1000);
        for (int i = 0; i < S; i++) {
            auto [o, a, b, k] = ops[i];
            if (o == 1) dc.add_edge(b, a, k - mid);
            else dc.add_edge(b, a, 1.0/(k + mid));
        }
        // f[0] = 1;
        // x <= f[c] <= x
        // f[c] >= f[0] * x && f[0] >= f[c] * 1/x
        for (int i = 1; i <= n; i++) if (score[i]) {
            dc.add_edge(0, i, score[i]);
            dc.add_edge(i, 0, 1.0/score[i]);
        }
        bool has = dc.spfa2(n + 2);
        if (has) return true; // 存在正环
        return false;
    };

    double l = 0, r = 10, eps = 1e-6, ans = 0;
    while ((r - l) > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    if (abs(ans) <= eps) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









