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
 *
*/

namespace EK_1 {
#define N 10010
#define M 200010
int n, m, S, T;
struct Edge {
    ll v;  // 对端
    ll c;  // 容量
    ll ne; // next
} e[M];
int h[N];
int idx = 1;
ll mf[N], pre[N];

// 链式前向星
void add(int a, int b, int c) {
    e[++idx] = {b, c, h[a]};
    h[a] = idx;
}

bool bfs() {
    memset(mf, 0, sizeof(mf));
    queue<int> q;
    q.push(S);
    mf[S] = INF;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {
            ll v = e[i].v;
            if (mf[v] == 0 && e[i].c) {
                mf[v] = min(mf[u], e[i].c);
                pre[v] = i;
                q.push(v);
                if (v == T) {
                    return true;
                }
            }
        }
    }
    return false;
}

ll ek() {
    ll flow = 0;
    while (bfs()) {
        int v = T;
        while (v != S) {
            int i = pre[v];
            e[i].c -= mf[T];
            e[i^1].c += mf[T];
            v = e[i^1].v;
        }
        flow += mf[T];
    }
    return flow;
}
}

using namespace EK_1;
/*
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 30
 */
void solve() {
    int a, b, c;
    cin >> n >> m >> S >> T;
    while (m--) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, 0);
    }
    cout << ek() << "\n";
}

int main() {
    solve();
    return 0;
}