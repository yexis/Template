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
 * 欧拉筛: 每个数是被最小质因子筛掉的
 * 线性筛: 每个数是被最小质因子筛掉的
 * 线性筛求因子数量
 * 线性筛求因子个数
 * 
*/


static constexpr int N = 1e6;
// 存储质数，从小到大
vector<int> prime;
// 是否为质数
bool not_prime[N + 1];
// 记录数i是被谁筛掉的，可有可无
int filter[N + 1];

// 记录 x 在其最小质因子p上的最大次数
// 如 x 在 p的指数 上的因数有 p^0,p^1,p^2,p^k，那么 g[x] = k + 1
int g[N + 1];
// 记录因子的数量
int f[N + 1];

void init() {
    for (int i = 2; i <= N; ++i) {
        if (!not_prime[i]) {
            filter[i] = i;
            f[i] = g[i] = 1 + 1;
            prime.push_back(i);
        }
        // 从小到大遍历质数
        for (int p : prime) {
            int m = i * p;
            if (m > N) break;
            not_prime[m] = true;
            filter[m] = p;
            if (i % p == 0) {
                g[m] = g[i] + 1;
                f[m] = f[i] / g[i] * g[m];
                // i % p == 0
                // 换言之，i 之前被 p 筛过了
                // 由于 prime 里面质数是从小到大的，所以 i 乘上其他的质数的结果 一定会被 p 筛掉
                // 就不需要在这里先筛一次，所以这里直接 break 掉就好了
              	// 证明：
              	// 假设 i / p = k，设 q 为质数，且 q > p 
              	// 那么，m = i * q = p * (k * q)，所以m一定会被 p 和 (k*q) 筛掉
                break;
            } else {
                g[m] = 2;
                f[m] = g[m] * f[i];
            }
        }
    }
    for (int i = 0; i <= 1000; i++) {
        cout << "filter:" << i << " " << f[i] << "\n";
    }
}


int main() {
    init();
    return 0;
}