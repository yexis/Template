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
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;


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


/*
 * 题目：https://ac.nowcoder.com/acm/contest/98256/F
 * 动态开点线段树 + 区间更新(lazy懒加载)
*/

struct Node {
    // 懒加载标记
    ll z;
    // 节点值
    ll v;
    // 区间长度
    ll len;
    
    Node(): len(0) {
        v = 0, z = 0;
    };
    
    Node(int l, int r) {
        len = r - l + 1;
        // 更新 v and z ...
    }
    
    Node operator+(const Node& b) {
        Node c;
        c.len = len + b.len;
        // 重载+操作
        return c;
    }
    
    // 具体操作
    void op() {
        // 具体操作
        // 更新 v and z ...
    }
};

// 线段树节点个数
const int N = 4e6 + 10;
struct SegTree {
    int cnt;
    Node tr[N];
    int ls[N];
    int rs[N];
    SegTree() {
        cnt = 0;
        memset(ls, 0, sizeof(ls));
        memset(rs, 0, sizeof(rs));
    }

    // 创建新节点(很重要！) ...
    int build(int l, int r) {
        int o = ++cnt;
        tr[o] = Node(l, r);
        return o;
    }

    // 标记下推 ...
    void push_down(int o, int l, int r) {
        if (tr[o].z) {
            tr[ls[o]].op();
            tr[rs[o]].op();
            tr[o].z = 0;
        }
    }

    // 更新父节点 ...
    void push_up(int o) {
        tr[o] = tr[ls[o]] + tr[rs[o]];
    }

    // 更新操作，o不是索引 ...
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            tr[o].op();
            return;
        }
        int m = (l + r) >> 1;
        if (!ls[o]) ls[o] = build(l, m);
        if (!rs[o]) rs[o] = build(m + 1, r);
        push_down(o, l, r);
        if (L <= m) {
            add(ls[o], l, m, L, R, u);
        }
        if (R > m) {
            add(rs[o], m + 1, r, L, R, u);
        }
        push_up(o);
    }

    // 询问操作，o不是索引 ...
    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        Node ans;

        int m = (l + r) >> 1;
        if (!ls[o]) ls[o] = build(l, m);
        if (!rs[o]) rs[o] = build(m + 1, r);
        push_down(o, l, r);
        if (L <= m) {
            ans = ans + ask(ls[o], l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(rs[o], m + 1, r, L, R);
        }
        return ans;
    }
};

void solve() {
    // 根节点
    int n = 100000;
    SegTree seg;
    // 一定需要先创建根节点
    int root = seg.build(1, n);
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}