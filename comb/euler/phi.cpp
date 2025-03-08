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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
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
 * phi值：小于等于x且与x互质的元素个数
*/

// 计算单个元素的phi值
struct PHI {
    int cal_phi(int m) {
        int phi = m, x = m;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                phi = phi * (i - 1) / i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            phi = phi * (x - 1) / x;
        }
        return phi;
    }
};


// 计算多个元素的phi值
struct PHI_MULTI {
    static constexpr int N = 1e5;
    // 存储质数，从小到大
    vector<int> prime;
    // 是否为质数
    bool not_prime[N + 1];
    // 欧拉函数
    int phi[N + 1];
    PHI_MULTI() {
        cal_mluti_phis();
    }

    void cal_mluti_phis() {
        phi[1] = 1;
        for (int i = 2; i <= N; ++i) {
            if (!not_prime[i]) {
                phi[i] = i - 1;
                prime.push_back(i);
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
                    phi[m] = p * phi[i];
                    break;
                } else {
                    phi[m] = (p - 1) * phi[i];
                }
            }
        }
    }
};


void solve() {
    PHI ph;
    for (int i = 1; i <= 1000; i++) {
        cout << "phi(" << i << ") : " << ph.cal_phi(i) << "\n";
    }

    PHI_MULTI phm;
    for (int i = 1; i <= 1000; i++) {
        cout << "phi(" << i << ") : " << phm.phi[i] << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









