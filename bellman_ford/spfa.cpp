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
*/

const int N = 1e5;
struct edge {
    int v;
    int w;
};
vector<edge> g[N];
int d[N];
int cnt[N];
int vis[N];
int pre[N];
queue<int> q;
int n, m, s;
int a, b, c;

bool spfa(int s) {
    d[s] = 0;
    q.push(s);
    vis[s] = true;
    while(q.size()) {
        auto u = q.front();
        q.pop();
        vis[u] = false;
        for (auto& [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pre[v] = u;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    // 存在负环
                    return true;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

// pii版本
bool spfa(vector<vector<pii>>& g, int s) {
    int n = g.size();

    vector<int> d(n), vis(n), cnt(n), pre(n);
    d[s] = 0, vis[s] = true;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        vis[u] = false;
        for (auto& [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pre[v] = u;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    return true;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < N; i++) {
        g[i].clear();
    }
    memset(d, INF, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back(edge{b, c});
        if (c >= 0) {
            g[b].push_back(edge{a, c});
        }
    }
    cout << (spfa(0) ? YES : NO) << "\n";
}

void solve2() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        if (w >= 0) {
            g[v].emplace_back(u, w);
        }
    }
    cout << (spfa(g, 0) ? YES : NO) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();    
    }
    return 0;
}