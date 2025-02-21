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
 * 二分图最大匹配
 * 匈牙利算法
*/
const int N = 1000;
const int M = 100010;
struct edge {
    // 对端
    int v;
    // 下一条边
    int ne;
} e[M];

int h[N];
int vis[N];
int match[N];
int idx = 0;

void add(int a, int b) {
    e[++idx] = {b, h[a]};
    h[a] = idx;
}

bool dfs(int u) {
    for (int i = h[u]; i; i = e[i].ne) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        vis[v] = 1;
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        add(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ans++;
    }
    cout << ans << "\n";

    return 0;
}