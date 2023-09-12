//
// Created by yex on 2023/3/24.
//
#include "../../main.h"
namespace SEG_MAX_1 {
    int n;
    vector<int> a;
    vector<int> c;
    void init(int nn) {
        n = nn;
        a.resize(n + 1);
        c.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        a[x] = u;
        for (int i = x; i <= n; i++) {
            c[i] = a[i];
            for (int j = 1; j < lb(i); j *= 2) {
                c[i] = max(c[i], c[i - j]);
            }
        }
    }
    int ask(int x, int y) {
        int ans = 0;
        while (y >= x) {
            ans = max(ans, a[y]);
            y--;
            while (y - lb(y) >= x) {
                ans = max(ans, c[y]);
                y -= lb(y);
            }
        }
        return ans;
    }
}

namespace SEG_MAX_2 {
    int n;
    vector<int> a, c;
    void init(int nn) {
        n = nn;
        a.resize(n + 1);
        c.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        a[x] = u;
        for (int i = x; i <= n; i += lb(i)) {
            c[i] = a[i];
            for (int j = 1; j < lb(i); j *= 2) {
                c[i] = max(c[i], c[i - j]);
            }
        }
    }
    int ask(int x, int y) {
        int ans = 0;
        while (y >= x) {
            ans = max(ans, a[y]);
            y--;
            while (y - lb(y) >= x) {
                ans = max(ans, c[y]);
                y -= lb(y);
            }
        }
        return ans;
    }
}


using SEG_MAX_2::init;
using SEG_MAX_2::lb;
using SEG_MAX_2::add;
using SEG_MAX_2::ask;
using SEG_MAX_2::a;
using SEG_MAX_2::c;

int bestTeamScore(vector<int>& aa, vector<int>& bb) {
    int m = aa.size();
    int mx = *max_element(begin(aa), end(aa));

    a.clear();
    c.clear();
    init(mx);

    vector<pair<int, int>> pr;
    for (int i = 0; i < m; i++) {
        pr.emplace_back(bb[i], aa[i]);
    }
    sort(pr.begin(), pr.end());

    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        f[i] = ask(1, pr[i].second) + pr[i].second;
        add(pr[i].second, f[i]);
    }
    return *max_element(f.begin(), f.end());
}
void test() {
    vector<int> a, b;
    // ans: 34
    a = {1, 3, 5, 10, 15};
    b = {1, 2, 3, 4, 5};
    cout << bestTeamScore(a, b) << endl;

    // ans: 16
    a = {4, 5, 6, 5};
    b = {2, 1, 2, 1};
    cout << bestTeamScore(a, b) << endl;

    // ans: 6
    a = {1, 2, 3, 5};
    b = {8, 9, 10, 1};
    cout << bestTeamScore(a, b) << endl;
}
int main() {
    test();
}
