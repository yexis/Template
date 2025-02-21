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
 * 动态开点线段树 
 * 计算区间和
*/

int root;
constexpr static int N = 2e6;
struct DynamicSegTree {
    int tot = 0;
    ll tr[N];
    int lc[N], rc[N];
    void add(int& o, int l, int r, int i, int u) {
        if (!o) o = ++tot;
        if (l == r) {
            tr[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(lc[o], l, m, i, u);
        } else {
            add(rc[o], m + 1, r, i, u);
        }
        tr[o] = tr[lc[o]] + tr[rc[o]];
    }

    ll ask(int o, int l, int r, int L, int R) {
        if (!o) return 0;
        if (L <= l && R >= r) {
            return tr[o];
        }
        ll ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(lc[o], l, m, L, R);
        }
        if (R > m) {
            ans += ask(rc[o], m + 1, r, L, R);
        }
        return ans;
    }
};


void solve() {
    int n;
    cin >> n;
    ll ans = 0;
     const int N = 1e9;
    DynamicSegTree seg;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += seg.ask(root, 1, N, x + 1, N);
        seg.add(root, 1, N, x, 1);
    }
    cout << ans << "\n";
}

int main() {

    return 0;
}