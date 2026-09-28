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
 * 割点 
 * 无向图
 * 
 * 割点判定法则：
 * 如果`x`不是根节点，当搜索树上存在`x`的一个子节点`y`，满足`low[y] >= dfn[x]`，那么`x`就是割点
 * 如果`x`是根节点，当搜索树上存在至少两个子节点`y1,y2`，满足上述条件，那么`x`就是割点
 * 
 * P3388
 * O(n + m)
 */
struct CutPoint {
    int n, m, tot, root;

    // (u, v, id)
    int edge_id;
    vector<vector<pii>> g;

    // 时间戳，追溯值
    vector<int> dfn, low;
    
    // 是否是割点
    vector<int> cut_point;

    // 是否是割边
    vector<int> cut_edge;

    CutPoint(int nn, int mm) {
        n = nn; m = mm; tot = 0; edge_id = 0;
        g.resize(n); dfn.resize(n, -1); low.resize(n, -1);
        cut_point.resize(n), cut_edge.resize(m);
    }

    void tarjan(int x, int last_id) {
        dfn[x] = low[x] = tot++;
        int child = 0; // 符合条件的子树个数
        for (auto [y, curr_id] : g[x]) {
            // 跳过返祖边
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
    }
    void add_edge(int u, int v) {
        g[u].push_back(pii(v, edge_id));
        g[v].push_back(pii(u, edge_id));
        edge_id++;
    }
    void set_root(int rt) {
        root = rt;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    
    CutPoint cp(n, m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        cp.add_edge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (cp.dfn[i] == -1) {
            cp.set_root(i);
            cp.tarjan(i, -1);
        }
    }
    
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (cp.cut_point[i]) {
            cnt++;
            ans.push_back(i + 1);
        }
    }
    cout << cnt << "\n";
    for (auto& e : ans) cout << e << " ";
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










