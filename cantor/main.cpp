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

/*
 * 
*/

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
 * 康托展开可以用来求一个 1\sim n 的任意排列的排名。
 * 排名：把 1 ~ n 的所有排列按字典序排序，这个排列的位次就是它的排名。
 * 如 [2,5,3,4,1]
 * 小于它的排列个数为 4! + 3 * 3! + 2! + 1 个
 * 考虑第1位 2: 小于2的数只有1，第一位取1的所有排列都小于它，则有4!个
 * 固定第1位，考虑第2位 5: 小于5的数有[1,2,3,4]，但是2已出现过，所以第2位可填[1,3,4]，则 3 * 3!
 * 固定前2位，考虑第3位 3: 小于3的数有[1,2]，但是2已出现过，所以第3位可填[1]，则 1 * 2!
 * 固定前3位，考虑第4位 4: 小于3的数有[1,2,3]，但是[2,3]已出现过，所以第4位可填[1]，则 1
 * 固定前4位，考虑第5位 1: 不存在小于1的数，且已经不存在还未出现的数
 */

struct BIT {
    int n;
    vector<int> tr;
    BIT() {

    }
    BIT(int nn) {
        n = nn;
        tr.resize(n + 1);
    }
    void resize(int nn) {
        n = nn;
        tr.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }
        return ans;
    }
};

struct Cantor {
    using ll = long long;
    const int mod = 1e9 + 7;
    vector<ll> fac;
    BIT bit;
    Cantor(int n) {
        bit.resize(n);
        fac.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            bit.add(i, 1);
        }

    }
    // a是[1,n]的一个排列
    int cal(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int x = a[i];
            bit.add(x, -1);
            ans += bit.ask(x) * fac[n - i - 1] % mod;
            ans %= mod;
        }
        return ans + 1;
    }
};

int main() {
    int n = 5;
    vector<int> a = {1,2,3,4,5};
    Cantor ct(n);
    cout << ct.cal(a) << "\n";
    return 0;
}