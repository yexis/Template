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
#define debug(x) cerr << (#x) << " = " << (x) << endl;
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
            if (m) ans %= m;
        }
        x *= x;
        if (m) x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 异或线性基
 * 高斯消元法
 * 
 * 性质一：设线性基组中一共有k个元素len(b) = k，则该组线性基能表示 2^k-1 个不同元素
 * 性质二：若len(b) < len(a)，说明一定能线性基表示出0
 * 性质三：线性基中组中的基 逆序排列
 * 性质四：线性基的任意子集的异或和不为0
*/

int n;
int row = 0; // row: 记录基向量的个数
vector<ll> b; // b: 记录每个基向量, b[0, row-1]表示所有基向量
vector<ll> bit; // bit: 记录第i位为1的基向量
void gauss(vector<ll>& a) {
    row = 0;
    n = a.size();
    b = a;
    bit = vector<ll>(64, 0);

    for (int i = 63; i >= 0; i--) {
        // 找到当前列(位)为1的行
        for (int j = row; j < n; j++) {
            if (b[j] >> i & 1) {
                swap(b[row], b[j]);
                break;
            }
        }
        // 不存在，跳过
        if ((b[row] >> i & 1) == 0) {
            continue;
        }
        // 将其他所有元素的该位的1消掉
        for (int j = 0; j < n; j++) {
            if (j != row && (b[j] >> i & 1)) {
                b[j] ^= b[row];
            }
        }
        // 第i位为1的线性基
        bit[i] = b[row];
        row++; 
        // 线性基的数量不可能超过n
        if (row == n) break;
    }
}

// 判断元素x能否被线性基表示
bool contains(ll x) {
    for (int i = 62; i >= 0; i--) {
        if (x >> i & 1) {
            if (bit[i]) x ^= bit[i];
        }
    }
    return x == 0;
}

// 计算线性基能表示的第k小，k从1开始
// 寻找[k小值]时，注意0能否被表示
ll k_min(ll k) {
    // 能表示出0，所以将k--，把0去掉
    if (row < n) k--;
    if (((ll)1 << row) - 1 < k) return -1;
    
    ll ans = 0;
    for (int i = 0; i < row; i++) {
        if (k >> i & 1) {
            ans ^= b[row - i - 1];
        }
    }
    return ans;
}

// 计算线性基能表示的第k大，k从1开始
// 寻找[k大值]时，0在最后
ll k_max(ll k) {
    ll tot = (1ll << row) - 1;
    if (row < n) tot++;
    if (k > tot) return -1;
    // 第 k 大 = 第 tot - k + 1 小
    return k_min(tot - k + 1);
} 

// 计算线性基能表示的元素中，x的排名
// 未验证过，感觉是对的
ll cal_rank(ll x) {
    // 先判断x能否表线性基表示
    if (!contains(x)) {
        return -1;
    }

    // 二分
    ll ans = -1;
    
    ll l = 1, r = (1ll << row) - 1;
    if (row < n) r++;

    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (k_min(mid) <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

// 计算线性基能表示的最大数
// 即 线性基所有元素的异或和
ll cal_max() {
    ll ans = 0;
    for (auto& e : b) ans ^= e;
    return ans;
}

// 计算线性基能表示的最小数
// 即 第1小的元素
ll cal_min() {
    return k_min(1);
}

// https://ac.nowcoder.com/acm/contest/111922/F
void solve() {
    auto cal = [&]() -> void {
        int n; cin >> n;
        vector<ll> a(n);
        for (auto& e : a) cin >> e;
        gauss(a);

        ll x = 1;
        while (contains(x)) {
            x *= 2;
        }
        cout << x << "\n";
    };

    int T; cin >> T;
    while (T--) {
        cal();
    }
    cout << "\n";
}

// https://acm.hdu.edu.cn/showproblem.php?pid=3949
void solve_hdu_3949() {
    int case_idx = 0;
    auto cal = [&]() -> void {
        printf("Case #%d:\n", ++case_idx);
        int n; cin >> n;
        vector<ll> a(n); 
        for (auto& e : a) cin >> e;
        gauss(a);

        int q; cin >> q;
        while (q--) {
            ll k; cin >> k;
            cout << k_min(k) << "\n";
        }
    };

    int T; cin >> T;
    while (T--) {
        cal();
    }
}


void solve_cal_max() {
    vector<ll> a = {5, 6, 7};
    gauss(a);
    cout << cal_max() << "\n";
}

void solve_k_max() {
    vector<ll> a = {1,2,4,8,16,16};
    gauss(a);
    for (auto& e : b) cout << e << " "; cout << "\n";
    cout << k_max(2) << "\n";
}

void solve_rank() {
    vector<ll> a = {1,2,4,8,16};
    gauss(a);
    cout << cal_rank(15) << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    
    // solve();
    // solve_hdu_3949();
    // solve_cal_max();
    // solve_k_max();
    solve_rank();
    return 0;
}









