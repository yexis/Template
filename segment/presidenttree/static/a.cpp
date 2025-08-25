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



/*
 * 主席树
 * 可持久化线段树
 * 静态主席树
*/

// 主席树模板 开始
static constexpr int N = 2e6 + 1000;
int root[N];
struct PresidentTree {
    // 全局编号
    int tot = 1;
    struct Node {
        int left, right;
        int val;
    } seg[N];

    /*
    * id: 节点编号
    * l: 节点所表示的区间左端点
    * r: 节点所表示的区间右端点
    */
    void build(int id, int l, int r) {
        if (l == r) {
            seg[id].val = 0;
            return;
        }
        int mid = (l + r) >> 1;
        seg[id].left = ++tot;
        seg[id].right = ++tot;
        build(seg[id].left, l, mid);
        build(seg[id].right, mid + 1, r);
        seg[id].val = seg[seg[id].left].val + seg[seg[id].right].val;
    }

    /*
    * pre: 上一个版本的线段树
    * now: 当前版本的线段树
    * l: 节点所表示的区间左端点
    * r:节点所表示的区间右端点
    * tot: 操作的位置
    * val: 变化量
    */
    void add(int pre, int now, int l, int r, int pos, int val) {
        if (l == r) {
            seg[now].val = seg[pre].val + val;
            return;
        }
        int mid = (l + r) >> 1;
        seg[now].left = seg[pre].left;
        seg[now].right = seg[pre].right;
        if (pos <= mid) {
            seg[now].left = ++tot;
            add(seg[pre].left, seg[now].left, l, mid, pos, val);
        } else {
            seg[now].right = ++tot;
            add(seg[pre].right, seg[now].right, mid + 1, r, pos, val);
        }
        seg[now].val = seg[seg[now].left].val + seg[seg[now].right].val;
    }

    // 计算now版本的线段树中，小于等于k的元素数量
    int ask(int now, int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return seg[now].val;
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(seg[now].left, o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(seg[now].right, o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
};
// 主席树模板 结束

void solve() {
    int n;
    vector<int> a = {1, 4, 4, 4, 5};
    n = a.size();
    int len = 5;

    // root[i]表示第i版线段树，第0版线段树为空树，便于求前缀和
    PresidentTree pt;
    root[0] = pt.tot++;
    pt.build(root[0], 1, len);

    for (int i = 0; i < n; i++) {
        root[i + 1] = pt.tot++;
        pt.add(root[i], root[i + 1], 1, len, a[i] + 1, 1);
    }

    int k = 4;
    cout << pt.ask(root[4], 1, 1, len, 1, k + 1) << "\n";
    cout << pt.ask(root[1], 1, 1, len, 1, k + 1) << "\n";
}

int main() {
    int T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}