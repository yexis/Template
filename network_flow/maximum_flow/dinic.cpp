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
 *
*/
namespace DINIC_1 {
#define N 10010
#define M 200010
int n, m, S, T;
struct Edge {
    ll v;
    ll c;
    ll ne;
} e[M];
// 记录点u第一条出边
int h[N];
// 记录点u所在的图层
int d[N];
// 记录u点当前的出边
int cur[N];
int idx = 1;
void add(int a, int b, int c) {
    e[++idx] = {b, c, h[a]};
    h[a] = idx;
}

// 分层
bool bfs() {
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {
            int v = e[i].v;
            if (d[v] == 0 && e[i].c) {
                d[v] = d[u] + 1;
                q.push(v);
                if (v == T) return true;
            }
        }
    }
    return false;
}

// 找增广路
ll dfs(int u, ll mf) {
    if (u == T) return mf;
    ll sum = 0;
    for (int i = cur[u]; i; i = e[i].ne) {
        // 点前弧优化
        cur[u] = i;
        int v = e[i].v;
        if (d[v] == d[u] + 1 && e[i].c) {
            ll f = dfs(v, min(mf, e[i].c));
            e[i].c -= f;
            e[i^1].c += f;
            sum += f;
            mf -= f;
            // 余量优化
            if (mf == 0) {
                break;
            }
        }
    }
    if (sum == 0) d[u] = 0;
    return sum;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        memcpy(cur, h, sizeof(h));
        flow += dfs(S, 1e9);
    }
    return flow;
}
}



using namespace DINIC_1;
/*
input:
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 30
 */
/*
ouput:
50
*/
void solve() {
    int a, b, c;
    cin >> n >> m >> S >> T;
    while (m--) {
    
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, 0);
    }
    cout << dinic() << "\n";
}

int main() {
    solve();
    return 0;
}