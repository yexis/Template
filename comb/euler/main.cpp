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

/*
 * 欧拉定理
 * 欧拉定理计算组合数 
 * 适用于模数为非质数的情况
*/

// 计算 C_n^k (mod m) m非质数
struct Euler {
    bool debug = false;
    // maxn取n的最大值
    static constexpr int maxn = 100'000;
    static constexpr int cmaxn = 100'000 + 1;
    // mod可以是质数，可以是合数
    int mod;
    // 小于等于mod与mod互质的元素个数
    int phi;

    // f[x] 表示 x! 化简后与mod互质的形式
    array<int, cmaxn> f;
    // inv[x] 表示 f[x] 的逆元
    array<int, cmaxn> inv;
    // p_fac 存储 mod的所有质因数
    vector<int> p_fac;
    // p[d][x] 表示 x中 d的个数
    // 例如: x = d * d * d * x0 【gcd(x0, d) = 1】 表示 x 中有 3 个 d
    vector<array<int, cmaxn> > p; 
    Euler(int _m) : mod(_m), phi(0) {
        cal_phi_2();
        cal_prime();
        init();
    }

    // 快速幂
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

    // 方法1：计算phi值: O(mod)
    void cal_phi() {
        for (int d = 1; d <= mod; d++) {
            if (gcd(d, mod) == 1) {
                phi++;
            }
        }
        if (debug) cout << "phi:" << phi << "\n";
    }

    // 方法2：计算phi值: O(sqrt(mod))
    void cal_phi_2() {
        phi = mod;
        int x = mod;
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
        if (debug) cout << "phi:" << phi << "\n";
    }

    // 质因数分解，便于将x化简后与mod互质
    // 可同时计算出phi值: O(sqrt(mod))
    void cal_prime() {
        int x = mod;
        for (int i = 2; i * i <= maxn; i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                }
                p_fac.push_back(i);
            }
        }
        if (x > 1) {
            p_fac.push_back(x);
        }
        p.resize((int)p_fac.size());
        if (debug) cout << "fac sz:" << (int)p_fac.size() << "\n";
    }

    void init() {
        int N = p_fac.size();
        f[0] = 1;
        for (int i = 1; i <= maxn; i++) {
            int x = i;
            vector<int> e(N);
            for (int j = 0; j < N; j++) {
                int fa = p_fac[j];
                while (x % fa == 0) {
                    x /= fa;
                    e[j]++;
                }
            }
            f[i] = f[i - 1] * x % mod;
            for (int j = 0; j < N; j++) {
                p[j][i] = p[j][i - 1] + e[j];
            }
        }
        // 计算逆元

        // 方法一：欧拉定理 x^{-1} = x^{\phi(m)-1} (mod m)
        // for (int i = 0; i <= maxn; i++) {
        //     inv[i] = power(f[i], phi - 1);
        // }

        // 方法二： 逆推 (x!)^{-1} = ((x+1)!)^{-1} * (x + 1) (mod m)
        inv[maxn] = power(f[maxn], phi - 1);
        for (int i = maxn; i > 0; i--) {
            int x = i;
            for (auto& fa : p_fac) {
                while (x % fa == 0) {
                    x /= fa;
                }
            }
            inv[i - 1] = inv[i] * x % mod;
        }
    }
    
    // C_n^k
    int C(int n, int k) {
        int ans = 1;
        ans *= f[n]; ans %= mod;
        ans *= inv[k]; ans %= mod;
        ans *= inv[n - k]; ans %= mod;
        for (int i = 0; i < p_fac.size(); i++) {
            auto& pi = p[i];
            ans *= power(p_fac[i], pi[n] - pi[k] - pi[n - k]);
            ans %= mod;
        }
        return ans;
    } 
};

Euler el(10);

class Solution {
public:
    bool hasSameDigits(string s) {
        // Euler el(10);
        int n = s.size();
        auto cal = [&](string& s1) {
            int n1 = s1.size();
            int n2 = n1 - 1;
            int ans = 0;
            for (int i = 0; i <= n2; i++) {
                ans += (s1[i] - '0') * el.C(n2, i);
                ans %= 10;
            }
            return ans;
        };

        string s1 = s.substr(0, n - 1);
        string s2 = s.substr(1, n - 1);
        return cal(s1) == cal(s2);
    }
};



void solve() {
    const int m = 1000000007;
    Euler el(m);
    el.cal_phi_2();
    cout << el.phi << "\n";
    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









