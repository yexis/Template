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
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * P8436
 * https://www.luogu.com.cn/problem/P8436
*/

struct EDCC {
    int n, m, tot;

    // 连通分量的根，判割点需要
    int root;

    // (u, v, id)
    int edge_id;
    vector<vector<int>> edges;
    vector<vector<pii>> g;
    // 原图中每个节点的度
    vector<int> deg;

    // (u, v, id)
    int new_edge_id;
    vector<vector<pii>> ng;
    // 新图中每个节点的度
    vector<int> new_deg;

    // 时间戳，追溯值
    vector<int> dfn, low;
    
    // 是否是割点
    vector<int> cut_point;

    // 是否是割边
    vector<int> cut_edge;

    // 模拟栈
    vector<int> stk;

    // 双连通分量组
    // cnt: 边双连通分量编号，即新图的节点编号
    // edcc: 节点属于哪个边双连通分量
    // redcc: edcc的反向关系，即新图节点→原图根节点
    int cnt;
    vector<int> edcc, redcc;
    vector<vector<int>> edcc_group;

    // 单连通分量组（也可以并查集维护）
    // conn_cnt: 单连通分量编号
    // conn: 节点属于哪个单连通分量
    // conn_group: 待定
    int conn_cnt;
    vector<int> conn;
    vector<vector<int>> conn_group;

    EDCC(int nn, int mm) {
        n = nn; m = mm; tot = 0; 
        edge_id = 0; g.resize(n); deg.resize(n);

        new_edge_id = 0; ng.resize(n); new_deg.resize(n);

        dfn.resize(n, -1); low.resize(n, -1);
        cut_point.resize(n), cut_edge.resize(m);
        cnt = 0; edcc.resize(n); edcc_group.resize(n); redcc.resize(n);

        conn_cnt = 0; conn.resize(n); conn_group.resize(n);
    }

    void tarjan(int x, int last_id) {
        dfn[x] = low[x] = tot++; 
        stk.push_back(x);
        conn[x] = conn_cnt;
        
        int child = 0; // 符合条件的子树个数
        for (auto [y, curr_id] : g[x]) {
            // 跳过返祖边，不是反边
            if (curr_id == last_id) continue;

            if (dfn[y] == -1) { // 若y尚未访问
                tarjan(y, curr_id);
                // 回x时，更新low，判割点
                // 注意这里取的是low[y]
                low[x] = min(low[x], low[y]);
                if (low[y] >= dfn[x]) {
                    child++;
                    if (x != root || child > 1) {
                        cut_point[x] = true;
                    }
                }
                // 判割边
                if (low[y] > dfn[x]) {
                    cut_edge[curr_id] = true;
                }
            } else { // 若y已经访问
                // 注意这里取的是dfn[y]
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            while(true) {
                int y = stk.back(); stk.pop_back();
                edcc[y] = cnt; edcc_group[cnt].push_back(y);
                if (y == x) break;
            }
            redcc[cnt] = x;
            cnt++;
        }
    }
    void add_edge(int u, int v) {
        edges.push_back({u, v});
        g[u].push_back(pii(v, edge_id));
        g[v].push_back(pii(u, edge_id));
        deg[u]++, deg[v]++;
        edge_id++;
    }
    void add_new_edge(int u, int v) {
        ng[u].push_back(pii(v, new_edge_id));
        ng[v].push_back(pii(u, new_edge_id));
        new_deg[u]++, new_deg[v]++;
        new_edge_id++;
    }
    void set_root(int rt) {
        root = rt;
    }
    void print() {
        cout << "edcc_group sz:" << cnt << "\n";
        for (int i = 0; i < cnt; i++) {
            cout << i << " : ";
            auto& e = edcc_group[i];
            for (auto u : e) cout << u << " "; cout << "\n";
        }

        cout << "edcc:" << "\n";
        for (int i = 0; i < n; i++) cout << edcc[i] << " "; cout << "\n";

    }
};


void solve() {
    int F, R; cin >> F >> R;
    
    EDCC edcc(F, R);
    for (int i = 0; i < R; i++) {
        int u, v; cin >> u >> v; u--, v--;
        edcc.add_edge(u, v);
    }

    for (int i = 0; i < F; i++) {
        if (edcc.dfn[i] == -1) {
            edcc.set_root(i);
            edcc.tarjan(i, -1);
            edcc.conn_cnt++; // 单连通分量编号
        }
    }
    edcc.print();
    
    // 创建新图，通过割边创建新图
    // 因为新图中的边 就是 原图中的割边
    for (int i = 0; i < R; i++) {
        if (edcc.cut_edge[i]) {
            int u = edcc.edges[i][0], ru = edcc.edcc[u];
            int v = edcc.edges[i][1], rv = edcc.edcc[v];
            edcc.add_new_edge(ru, rv);
        }
    }

    int ans = 0;
    vector<int> deg1_cnt(edcc.conn_cnt);
    for (int u = 0; u < edcc.cnt; u++) {
        if (edcc.new_deg[u] == 1) {
            deg1_cnt[edcc.conn[edcc.redcc[u]]]++;
        }
    }

    // 全局只有一个单连通分量
    if (edcc.conn_cnt == 1) {
        for (auto e : deg1_cnt) {
            ans += max(0, (e + 1) / 2);
        }
    } else {
        // 全局有多个单连通分量
        for (auto e : deg1_cnt) {
            if (e <= 2) continue;
            ans += e / 2;
        }
        ans += edcc.conn_cnt;
    }
    
    cout << ans << "\n";
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









