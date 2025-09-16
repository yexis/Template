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

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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
 * 高维前缀和 sum-over-subset dp
 * 适用场景：
 * 计算集合所有子集的和（一定正确，思考）
 * 计算集合所有机子的max/min（一定正确）
 * 
 * 
 * 
 * 二维前缀和的计算方法(按维度计算每一维的前缀和):
 * ```
 * 一开始，f[i][j] 表示的只是格子 (i, j) 的值
 * for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] += f[i][j - 1];
 * 现在，f[i][j] 表示的是所有 (i, 1 ~ j) 的和
 * for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] += f[i - 1][j];
 * 现在，f[i][j] 表示的是所有 (1 ~ i, 1 ~ j) 的和
 * ```
 * 对于二进制，可以将每一位考虑成维度；只是，每个维度上只有0和1两个位置。
 * 
 * 为什么 求对于bitmask的子集和(n个置位) = 求n位空间坐标系的前缀和？
 * 考虑mask = 7，考虑每个数的来源：
 * 0:
 * 1:0 
 * 2:0 
 * 3:2 1 
 * 4:0 
 * 5:4 1 
 * 6:4 2 
 * 7:6 5 3 
 * 7需要 +6 +5，看起来4被+了2次，但实际只加了1次，因为7在+5的时候，5还没有+4（只+了1），看下面分析
 * 
 * 
 * 考虑mask = 7(0b111)，三维空间(x, y, z)，可以画出三维图形
 * 1. align x -> 沿x求和
 * 100 += 000
 * 101 += 001
 * 110 += 010
 * 111 += 011
 * 
 * 2. align y -> 沿y求和
 * 010 += 000
 * 110 += 100 (+ 000)
 * 011 += 001
 * 111 += 101 (+ 001)
 * 
 * 3. align z -> 沿z求和
 * 001 += 000 
 * 011 += 010 (+ 000)
 * 101 += 100 (+ 000)
 * 111 += 110 (+ 100 + 000 + 010)
 * 
*/

// 应用场景一
// 找出数组a[i] * a[j] 的最大乘积
// 要求 i, j 不相同，且 a[i] 和 a[j] 无公共置位
// 要求没有公共置位，说明 a[i] 和 a[j] 互为对方补集的子集
void sosdp_max(vector<int>& a) {
    int n = a.size();
    int mx = *max_element(a.begin(), a.end());

    int m = 32 - __builtin_clz(mx);
    int f[1 << m]; memset(f, 0, sizeof(f));
    for (auto& e : a) f[e] = e;

    for (int d = 0; d < m; d++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (mask >> d & 1) {
                f[mask] = max(f[mask], f[mask ^ (1 << d)]);
            }
        }
    }
    // 此时，f[mask] 表示 mask 及其所有二进制子集的最大值

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (ll)a[i] * f[((1 << m) - 1) ^ a[i]]);
    }
    return ans;
}

// 应用场景二
// 找出mask及其所有二进制子集的和
void sosdp_max(vector<int>& a) {
    int n = a.size();
    int mx = *max_element(a.begin(), a.end());

    int m = 32 - __builtin_clz(mx);
    int f[1 << m]; memset(f, 0, sizeof(f));
    for (auto& e : a) f[e] = e;

    for (int d = 0; d < m; d++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (mask >> d & 1) {
                f[mask] += f[mask ^ (1 << d)];
            }
        }
    }
    // 此时，f[mask] 表示 mask 及其所有二进制子集的和
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& e : a) cin >> e;
    int mx = *max_element(a.begin(), a.end());
    int m = 32 - __builtin_clz(mx);

    ll f[1 << m]; memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
        f[a[i]] = a[i];
    }

    // 枚举维度
    for (int d = 0; d < m; d++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            // mask >> d & 1为0时，不用考虑
            // 因为在第d位，f[][]...[i] += f[][]...[i - 1]
            if (mask >> d & 1) {
                f[mask] = max(f[mask], f[mask ^ (1 << d)]);
            }
        }

    }
    // 此时，f[mask]表示的是mask的所有子集的最大值
    // 前缀和也可使用该方式求得
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










