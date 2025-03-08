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

// 计算多个元素的phi值
struct FactorSum {
    static constexpr int N = 1e6;
    // 存储质数，从小到大
    vector<int> prime;
    // 是否为质数
    bool not_prime[N + 1];
    // 欧拉函数
    int f[N + 1];
    // g[i]表示i的最小质因子的 p^0 + p^1 + p^2 + ... + p^k 形式
    int g[N + 1];
    FactorSum() {
        cal_factor_sum();
    }

    void cal_factor_sum() {
        f[0] = g[0] = 1;
        for (int i = 2; i <= N; ++i) {
            if (!not_prime[i]) {
                prime.push_back(i);
                g[i] = f[i] = i + 1;
            }
            // 从小到大遍历质数
            for (int p : prime) {
                if (i * p > N) break;
                int m = i * p;
                not_prime[m] = true;
                if (i % p == 0) {
                    // i % p == 0
                    // 换言之，i 之前被 p 筛过了
                    // 由于 prime 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定会被 p 的某个倍数筛掉
                    // 就不需要在这里先筛一次，所以这里直接 break 掉就好了
                    g[m] = g[i] * p[j] + 1;
                    f[m] = f[i] / g[i] * g[m];
                    break;
                } else {
                    g[m] = p[j] + 1;
                    f[m] = f[i] * g[m];
                }
            }
        }
    }
};

void solve() {
    FactorSum fs;
    for (int i = 0; i <= 1000) {
        cout << i << " " << fs.f[i] << "\n";
    }
}

int main() {
    solve();
    return 0;
}