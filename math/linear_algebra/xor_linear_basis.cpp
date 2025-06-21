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
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 异或线性基
 * 高斯消元法
*/

int row = 0; // row: 记录基向量的个数
vector<ll> b; // b: 记录每个基向量
vector<ll> bit; // bit: 记录第i位为1的基向量
void gauss(vector<ll>& a) {
    row = 0;
    b = a;
    bit = vector<ll>(63, 0);
    int n = b.size();
    for (int i = 62; i >= 0; i--) {
        for (int j = row; j < n; j++) {
            if (b[j] >> i & 1) {
                swap(b[row], b[j]);
                break;
            }
        }
        if ((b[row] >> i & 1) == 0) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j != row && (b[j] >> i & 1)) {
                b[j] ^= b[row];
            }
        }
        bit[i] = b[row];
        row++; 
        if (row == n) break;
    }
}

bool contains(vector<ll>& base, ll x) {
    for (int i = 62; i >= 0; i--) {
        if (x >> i & 1) {
            if (base[i]) x ^= base[i];
        }
    }
    return x == 0;
}

void solve() {
    vector<ll> a = {1,2,3,4,5,6,7,8,9,10};
    gauss(a);
    for (int i = 0; i < row; i++) cout << b[i] << " "; cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









