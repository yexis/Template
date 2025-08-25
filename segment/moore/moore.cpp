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
 * 
*/

// 摩尔投票的线段树
// 基于pair<int, int> 的实现
typedef pair<int, int> pii;
pii operator+(const pii& a, const pii& b) {
    pii res = a;
    if (a.first == b.first) {
        res.second = a.second + b.second;
    } else if (a.second >= b.second) {
        res.second = a.second - b.second;
    } else {
        res.first = b.first;
        res.second = b.second - a.second;
    }
    return res;
};

pii f[80010];
void init() {
    for (int i = 0; i < 80010; i++) {
        f[i] = pii();
    } 
}
void add(int o, int l, int r, int i, int u) {
    if (l == r) {
        f[o] = pii(u, 1); 
        return;
    }
    int m = (l + r) >> 1;
    if (i <= m) {
        add(o * 2, l, m, i, u);
    } else {
        add(o * 2 + 1, m + 1, r, i, u);
    } 
    f[o] = f[o * 2] + f[o * 2 + 1];
}

pii ask(int o, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return f[o];
    }
    pii ans;
    int m = (l + r) >> 1;
    if (L <= m) {
        ans = ans + ask(o * 2, l, m, L, R);
    }
    if (R > m) {
        ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
    }
    return ans;
}

void solve() {
    vector<int> a = {4, 1, 2, 2, 3, 1, 3, 4};
    int n = a.size();
    for (int i = 0; i < n; i++) {
        add(1, 1, n, i + 1, a[i]);
    }
    pii res = ask(1, 1, n, 1, n);
    cout << res.first << " " << res.second << "\n";
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









