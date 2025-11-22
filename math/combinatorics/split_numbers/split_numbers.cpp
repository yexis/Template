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
 * 分拆数
*/

// 分拆数: 自然数 n 的分拆方法数（各部可相等）
// p(n, k)表示自然数 n 的拆分成k个部分的分拆方法数
// p(n,k) = p(n-1,k-1)+p(n-k,k)
ll p[10005][1005]; 
auto _ = []() -> int {
    memset(p, 0, sizeof(p));
    p[0][0] = 1;
    for (int i = 1; i <= 10000; i++) {
        for (int k = 1; k <= 1000; k++) {
            if (i - k >= 0) {
                p[i][k] = p[i - 1][k - 1] + p[i - k][k];
                p[i][k] %= mod;
            }
        }
    }
    return 0;
}();
ll split_numbers(int n, int k) {
    return p[n][k];
}
void test_1() {
    for (int i = 1; i <= 10; i++) {
        for (int k = 1; k <= i; k++) {
            cout << i << " " << k << " " << p[i][k] << "\n";
        }
    }
}

// version-1
// 互异分拆数: 自然数 n 的各部分互不相同的分拆方法数 （各部不可相等）
// pd(n, k)表示自然数 n 的拆分成k个互异部分的分拆方法数
// pd(n,k) = pd(n - k, k - 1) + pd(n - k, k)
ll pd[100005][355];
auto __ = []() -> int {
    memset(pd, 0, sizeof(pd));
    pd[0][0] = 1;
    for (int i = 1; i <= 100000; i++) {
        for (int k = 1; k <= 350; k++) {
            if (i - k >= 0) {
                pd[i][k] = pd[i - k][k - 1] + pd[i - k][k];
                pd[i][k] %= mod;
            }
        }
    }
    return 0;
}();
ll split_numbers_different(int n, int k) {
    return pd[n][k];
}

// version-2
// 互异k部分拆数：空间优化版本
// pd(n, k)表示自然数 n 的拆分成k个互异部分的分拆方法数
// pd(n,k) = pd(n - k, k - 1) + pd(n - k, k)
ll split_numbers_different_optimized(int n, int K) {
    if (K * (K + 1) / 2 > n) return 0;
    vector<ll> f(n + 1); f[0] = 1;
    for (int k = 1; k * (k + 1) / 2 <= n; k++) {
        vector<ll> nf(n + 1);
        for (int i = k; i <= n; i++) {
            nf[i] = f[i - k] + nf[i - k];
            nf[i] %= mod;
        }
        swap(f, nf);
        if (k == K) break;
    }
    return f[n];
}
// version-3
// 互异k部分拆数：空间优化版本
// pd(n, k)表示自然数 n 的拆分成k个互异部分的分拆方法数
ll split_numbers_different_optimized_v3(int n, int K) {
    // pd(n,k) = pd(n - k, k - 1) + pd(n - k, k)
    if (K * (K + 1) / 2 > n) return 0;
    ll f[n + 1][2]; memset(f, 0, sizeof(f)); f[0][0] = 1;
    for (int k = 1; k * (k + 1) / 2 <= n; k++) {
        for (int i = 0; i <= n; i++) {
            f[i][k & 1] = 0;
        }
         // 划分成k个部分，必须至少k个数
        for (int i = k; i <= n; i++) {
            f[i][k & 1] = f[i - k][i & 1 ^ 1] + f[i - k][i & 1];
            f[i][k & 1] %= mod;
        }
        if (k == K) break;
    }
    return f[n][K & 1];
}
void test_2() {
    for (int i = 1; i < 10; i++) {
        for (int k = 1; k <= i; k++) {
            cout << i << " " << k << " " << split_numbers_different_optimized_v3(i, k) << "\n";
        }
    }
}

// version-4: 互异分拆数总数
ll split_numbers_different_optimized_v4(int n) {
    // pd(n,k) = pd(n - k, k - 1) + pd(n - k, k)
    ll ans = 0;
    ll f[n + 1][2]; memset(f, 0, sizeof(f)); f[0][0] = 1;
    for (int k = 1; k * (k + 1) / 2 <= n; k++) {
        for (int i = 0; i <= n; i++) {
            f[i][k & 1] = 0;
        }
        for (int i = k; i <= n; i++) {
            f[i][k & 1] = f[i - k][i & 1 ^ 1] + f[i - k][i & 1];
            f[i][k & 1] %= mod;
        }
        ans += f[n][k & 1];
        ans %= mod;
    }
    return ans;
}
void test_4() {
    for (int i = 1; i < 10; i++) {
        cout << i << " " << split_numbers_different_optimized_v4(i) << "\n";
    }
}


void solve() {
    test_2();
}

int main() {
    solve();
    return 0;
}