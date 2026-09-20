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
 * SCC缩点
 * https://www.luogu.com.cn/problem/P2341
*/

struct TarjanSCC {
    int n;
    // 时间戳编号，强连通分量个数
    // 编号都从1开始
    int tot, cnt;

    vector<vector<int>> g;
    
    // 时间戳，追溯值
    vector<int> dfn, low; 

    // 模拟栈，是否在栈中
    vector<int> stk, in_stk;

    // 强连通分量编号，scc的大小
    vector<int> scc, siz; 

    // 记录强连通分量入度和出度
    vector<int> deg_in, deg_out;

    TarjanSCC(vector<vector<int>>& gg) {
        tot = cnt = 0;
        g = gg, n = g.size();
        dfn.resize(n); low.resize(n);
        in_stk.resize(n);
        scc.resize(n), siz.resize(n + 1);
        deg_in.resize(n + 1); deg_out.resize(n + 1);
    }
    void tarjan(int x) {
        dfn[x] = low[x] = ++tot;
        stk.push_back(x); in_stk[x] = 1;
        for (auto& y : g[x]) {
            if (!dfn[y]) {
                tarjan(y);
                low[x] = min(low[x], low[y]);
            } else if (in_stk[y]) {
                low[x] = min(low[x], dfn[y]);
            }
        }
        // 若x是scc的根
        if (dfn[x] == low[x]) {
            int y; ++cnt;
            while (true) {
                y = stk.back(); stk.pop_back(); in_stk[y] = 0;
                scc[y] = cnt; ++siz[cnt];
                if (y == x) break;
            }
        }
    }
};


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v); 
    }

    TarjanSCC tj(g);

    for (int i = 0; i < n; i++) {
        if (!tj.dfn[i]) tj.tarjan(i);
    }

    for (int x = 0; x < n; ++x) {
        for (int y : g[x]) {
            if (tj.scc[x] != tj.scc[y]) {
                ++tj.deg_out[tj.scc[x]];
            }
        }
    }

    // cout << "cnt:" << tj.cnt << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << "(" << i << " " << tj.scc[i] << ")\n";
    // }
    
    int sum = 0, zeros = 0;
    for (int i = 1; i <= tj.cnt; i++) {
        if (tj.deg_out[i] == 0) {
            sum = tj.siz[i];
            ++zeros;
        }
    }

    // 只允许存在一个出度为0的scc
    if (zeros > 1) sum = 0;

    cout << sum << "\n";
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









